#fixed
import contextlib
import inspect
import json
import os
import pathlib
import typing as tp
import uuid

import numpy as np
import pandas as pd
import sklearn
from sklearn.metrics._scorer import _check_multimetric_scoring
from sklearn.model_selection._validation import _score
from sklearn.tree import DecisionTreeRegressor, DecisionTreeClassifier
from sklearn.base import BaseEstimator
from sklearn.base import clone
from sklearn.utils import check_random_state
from sklearn.utils.estimator_checks import check_estimator

class MyAdaBoostClassifier:
    """
    Multiclass AdaBoost implementation with SAMME.R algorithm
    """
    big_number = 1 << 32
    eps = 1e-8

    def __init__(
            self,
            n_estimators: int,
            base_estimator: tp.Type[sklearn.base.BaseEstimator],
            seed: int,
            **kwargs
    ):
        """
        :param n_estimators: count of estimators
        :param base_estimator: base estimator (practically tree classifier)
        :param seed: global seed
        :param kwargs: keyword arguments of base estimator
        """
        self.n_classes = None
        self.error_history = []  # this is to track model learning process
        self.n_estimators = n_estimators
        self.rng = np.random.default_rng(seed)
        self.base_estimator = base_estimator
        self.base_estimator_kwargs = kwargs
        # deduce which keywords are used to set seed for an estimator (sklearn or own tree implementation)
        signature = inspect.signature(self.base_estimator.__init__)
        self.seed_keyword = None
        if 'seed' in signature.parameters:
            self.seed_keyword = 'seed'
        elif 'random_state' in signature.parameters:
            self.seed_keyword = 'random_state'
        self.estimators = []

    def create_new_estimator(
            self,
            seed: int
    ):
        """
        create new base estiamtor with proper keywords
        and new *unique* seed
        :param seed:
        :return:
        """

        params = self.base_estimator_kwargs.copy()
        if self.seed_keyword:
            params[self.seed_keyword] = seed
#        new_estimator = DecisionTreeClassifier(random_state=seed) #self.base_estimator(**self.base_estimator_kwargs)
        
        return self.base_estimator(**params)

    def get_new_weights(self, 
                        true_labels: np.ndarray, 
                        predictions: np.ndarray, 
                        weights: np.ndarray):
        """
        Обновляет веса объектов на основе алгоритма SAMME.R.
        
        Parameters:
            true_labels (np.ndarray): Истинные метки классов (размер n).
            predict_proba (np.ndarray): Предсказанные вероятности классов (размер n x n_classes).
            weights (np.ndarray): Текущие веса объектов (размер n).
            n_classes (int): Общее количество классов.
            
        Returns:
            np.ndarray: Новый массив весов (размер n).
        """
        n_classes = self.n_classes
        # Масштабирование вероятностей (логарифм и нормализация по числу классов)
        eps = self.eps  # Чтобы избежать деления на ноль
        probabilities = np.clip(predictions, eps, 1 - eps)  # Убираем нули и единицы
        log_proba = np.log(probabilities)
        
        # Вычисляем значения обновления весов
        # Индекс правильного класса для каждого объекта
        true_class_log_proba = log_proba[np.arange(len(true_labels)), true_labels]
        # Отрицательная "ошибка"
        weight_update = -true_class_log_proba + (1 / n_classes) * log_proba.sum(axis=1)
        
        # Обновляем веса
        new_weights = weights * np.exp(weight_update)
        
        # Нормируем веса
        new_weights /= np.sum(new_weights)
        
        return new_weights

    @staticmethod
    def get_estimator_error(
            estimator: sklearn.base.BaseEstimator,
            X: np.ndarray,
            y: np.ndarray,
            weights: np.ndarray
    ):
     #-> float:
        """
        Вычисляет взвешенную ошибку эстиматора на выборке с весами.

        Parameters:
            estimator (BaseEstimator): Обученный оценщик (например, DecisionTreeClassifier).
            X (np.ndarray): Матрица признаков (размер n x m).
            y (np.ndarray): Вектор истинных меток классов (размер n).
            weights (np.ndarray): Вектор весов объектов (размер n).

        Returns:
            float: Взвешенная ошибка эстиматора.
        """

        # Предсказания модели
        #predictions = estimator.predict(X)
        
        # Индикатор неправильной классификации (1 для ошибок, 0 для правильных)
        #misclassified = (predictions != y).astype(float)
        
        # Взвешенная ошибка
#        weighted_error = np.sum(weights * misclassified) / np.sum(weights)
        probabilities = np.clip(estimator.predict_proba(X), MyAdaBoostClassifier.eps, 1 - MyAdaBoostClassifier.eps)
        weighted_error = np.sum(weights * (1 - probabilities[np.arange(len(y)), y]))
        
        return weighted_error

    def fit(self, X: np.ndarray, y: np.ndarray):
        """
        Sequentially fit estimators with updated weights on each iteration using SAMME.R algorithm.
        
        :param X: [n_samples, n_features]
        :param y: [n_samples]
        :return: self
        """
        self.error_history = []

        # Compute the number of classes for internal use
        self.n_classes = len(np.unique(y, return_counts=False))
        n_samples = X.shape[0]

        # Initialize weights uniformly over all samples
        weights = np.full((n_samples,), fill_value=1 / n_samples)

        # Sequentially fit each model and adjust weights
        for seed in self.rng.choice(
                max(MyAdaBoostClassifier.big_number, self.n_estimators),
                size=self.n_estimators,
                replace=False
        ):
            # Generate a unique seed for reproducibility
          #  seed = self.rng.integers(0, 1e6)

            # Add newly created estimator
            estimator = self.create_new_estimator(seed)
            self.estimators.append(estimator)

            # Fit the estimator to data with current sample weights
            estimator.fit(X=X, y=y, sample_weight=weights)

            # Get predicted probabilities for SAMME.R
            predict_proba = np.clip(estimator.predict_proba(X), MyAdaBoostClassifier.eps, 1 - MyAdaBoostClassifier.eps)

            # Compute estimator error (misclassification rate weighted by sample weights)
            estimator_error = MyAdaBoostClassifier.get_estimator_error(estimator, X, y, weights)
			
            if estimator_error == 0:
                self.error_history.append(estimator_error)
                weights[:] = 1 / len(weights)  # Сбрасываем веса равномерно
                continue

        	
            estimator_error = max(estimator_error, self.eps)
            
            # Calculate alpha (model weight) for SAMME.R
            #estimator_alpha = 0.5 * np.log((1 - estimator_error) / estimator_error)

                # Update sample weights using SAMME.R formula
            true_class_log_proba = np.log(predict_proba[np.arange(n_samples), y])
            weights_update_factor = -true_class_log_proba + (1 / self.n_classes) * np.sum(np.log(predict_proba), axis=1)
            #weights *= np.exp(weights_update_factor)
            weights = self.get_new_weights(y, predictions=predict_proba, weights=weights)
            # Normalize weights
            #weights /= np.sum(weights)

            # Append the error to the error history
            self.error_history.append(estimator_error)

        return self
    
    def predict_proba(
            self,
            X: np.ndarray
    ):
        """
        predicts probability of each class
        :param X: [n_samples, n_features]
        :return: array of probabilities of a shape [n_samples, n_classes]
        """
        # calculate probabilities from each estimator and average them, clip logarithms using self.eps
        ...
        # use softmax to ensure probabilities sum to 1, use numerically stable implementation

        predict_proba = np.array([est.predict_proba(X) for est in self.estimators])
        
        probas = np.array([np.exp(line) / np.sum(np.exp(line)) for line in predict_proba])[0]
        
        return probas

    def predict(
            self,
            X: np.ndarray
    ):
        """
        predicts class (use predicted class probabilities)
        :param X: [n_samples, n_features]
        :return: array class predictions of a shape [n_samples]
        """        
        probas = self.predict_proba(X)
        predictions = np.array([np.argmax(line) for line in probas])
        return predictions

class MyBinaryTreeGradientBoostingClassifier:
    """
    *Binary* gradient boosting with trees using
    negative log-likelihood loss with constant learning rate.
    Trees are to predict logits.
    """
    big_number = 1 << 32
    eps = 1e-8

    def __init__(
            self,
            n_estimators: int,
            learning_rate: float,
            seed: int,
            **kwargs
    ):
        """
        :param n_estimators: estimators count
        :param learning_rate: hard learning rate
        :param seed: global seed
        :param kwargs: kwargs of base estimator which is sklearn TreeRegressor
        """
        self.n_estimators = n_estimators
        self.learning_rate = learning_rate
        self.initial_logits = None
        self.rng = np.random.default_rng(seed)
        self.base_estimator = DecisionTreeRegressor
        self.base_estimator_kwargs = kwargs
        self.estimators = []
        self.loss_history = []  # this is to track model learning process

    def create_new_estimator(self, seed):
        params = self.base_estimator_kwargs.copy()
        signature = inspect.signature(self.base_estimator.__init__)
        seed_keyword = None
        if 'seed' in signature.parameters:
            seed_keyword = 'seed'
        elif 'random_state' in signature.parameters:
            seed_keyword = 'random_state'

        if seed_keyword:
            params[seed_keyword] = seed
        
        estimator = self.base_estimator(**params)
        return estimator

    @staticmethod
    def cross_entropy_loss(
            true_labels: np.ndarray,
            logits: np.ndarray
    ):
        """
        compute negative log-likelihood for logits,
        use clipping for logarithms with self.eps
        or use numerically stable special functions.
        This is used to track model learning process
        :param true_labels: [n_samples]
        :param logits: [n_samples]
        :return:
        """

        probas = 1 / (1 + np.exp(-logits))
        y_pred = np.clip(probas, MyBinaryTreeGradientBoostingClassifier.eps, 1 - MyBinaryTreeGradientBoostingClassifier.eps)
        
        nll = -np.sum(true_labels * np.log(y_pred) + (1-true_labels)*np.log(1-y_pred))
        return nll

    @staticmethod
    def cross_entropy_loss_gradient(
            true_labels: np.ndarray,
            logits: np.ndarray
    ):
        """
        compute gradient of log-likelihood w.r.t logits,
        use clipping for logarithms with self.eps
        or use numerically stable special functions
        :param true_labels: [n_samples]
        :param logits: [n_samples]
        :return:
        """
        y_pred = 1 / (1 + np.exp(-logits))
#        y_pred = np.clip(y_pred, MyBinaryTreeGradientBoostingClassifier.eps, 1-MyBinaryTreeGradientBoostingClassifier.eps)
        #gradient = y_pred - true_labels
        gradient = y_pred - true_labels
        return gradient

    def fit(
            self,
            X: np.ndarray,
            y: np.ndarray
    ):
        """
        sequentially fit estimators to reduce residual on each iteration
        :param X: [n_samples, n_features]
        :param y: [n_samples]
        :return: self
        """
        self.loss_history = []
        # only should be fitted on datasets with binary target
        assert (np.unique(y) == np.arange(2)).all()
        # init predictions with mean target (mind that these are logits!)
        self.initial_logits = np.log(np.sum(y) / (y.shape[0] - np.sum(y)))
        # create starting logits
        logits = self.initial_logits
        # init loss history with starting negative log-likelihood
        self.loss_history.append(self.cross_entropy_loss(y, logits))
        # sequentially fit estimators with random seeds
        for seed in self.rng.choice(
                max(self.big_number, self.n_estimators),
                size=self.n_estimators,
                replace=False
        ):
            estimator = self.create_new_estimator(seed)
            # add newly created estimator
            self.estimators.append(estimator)
            # compute gradient
            gradient = self.cross_entropy_loss_gradient(true_labels=y, logits=logits)
            # fit estimator on gradient residual
            estimator.fit(X=X, y=gradient)
            # adjust logits with learning rate
            logits -= self.learning_rate * gradient
            # append new loss to history
            self.loss_history.append(self.cross_entropy_loss(y, logits))
        return self

    def predict_proba(
            self,
            X: np.ndarray
    ):
        """
        :param X: [n_samples]
        :return:
        """
        # init logits using precalculated values
        logits = self.initial_logits
        # sequentially adjust logits with learning rate
        for estimator in self.estimators:
            logits += self.learning_rate * estimator.predict(X)
        # don't forget to convert logits to probabilities
        return 1 / (1+ np.exp(logits))

    def predict(
            self,
            X: np.ndarray
    ):
        """
        calculate predictions using predict_proba
        :param X: [n_samples]
        :return:
        """
        probas = self.predict_proba(X)
        predictions = (probas[:,1] > 0.5).astype(int)
        return predictions


class Logger:
    """Logger performs data management and stores scores and other relevant information"""

    def __init__(self, logs_path: tp.Union[str, os.PathLike]):
        self.path = pathlib.Path(logs_path)

        records = []
        for root, dirs, files in os.walk(self.path):
            for file in files:
                if file.lower().endswith('.json'):
                    uuid = os.path.splitext(file)[0]
                    with open(os.path.join(root, file), 'r') as f:
                        try:
                            logged_data = json.load(f)
                            records.append(
                                {
                                    'id': uuid,
                                    **logged_data
                                }
                            )
                        except json.JSONDecodeError:
                            pass
        if records:
            self.leaderboard = pd.DataFrame.from_records(records, index='id')
        else:
            self.leaderboard = pd.DataFrame(index=pd.Index([], name='id'))

        self._current_run = None

    class Run:
        """Run incapsulates information for a particular entry of logged material. Each run is solitary experiment"""

        def __init__(self, name, storage, path):
            self.name = name
            self._storage = storage
            self._path = path
            self._storage.append(pd.Series(name=name))

        def log(self, key, value):
            self._storage.loc[self.name, key] = value

        def log_values(self, log_values: tp.Dict[str, tp.Any]):
            for key, value in log_values.items():
                self.log(key, value)

        def save_logs(self):
            with open(self._path / f'{self.name}.json', 'w+') as f:
                json.dump(self._storage.loc[self.name].to_dict(), f)

        def log_artifact(self, fname: str, writer: tp.Callable):
            with open(self._path / fname, 'wb+') as f:
                writer(f)

    @contextlib.contextmanager
    def run(self, name: tp.Optional[str] = None):
        if name is None:
            name = str(uuid.uuid4())
        # elif name in self.leaderboard.index:
        #     raise NameError("Run with given name already exists, name should be unique")
        else:
            name = name.replace(' ', '_')
        self._current_run = Logger.Run(name, self.leaderboard, self.path / name)
        os.makedirs(self.path / name, exist_ok=True)
        try:
            yield self._current_run
        finally:
            self._current_run.save_logs()


def load_predictions_dataframe(filename, column_prefix, index):
    with open(filename, 'rb') as file:
        data = np.load(file)
        dataframe = pd.DataFrame(data, columns=[f'{column_prefix}_{i}' for i in range(data.shape[1])],
                                 index=index)
        return dataframe


class ExperimentHandler:
    """This class perfoms experiments with given model, measures metrics and logs everything for thorough comparison"""
    stacking_prediction_filename = 'cv_stacking_prediction.npy'
    test_stacking_prediction_filename = 'test_stacking_prediction.npy'

    def __init__(
            self,
            X_train: pd.DataFrame,
            y_train: pd.Series,
            X_test: pd.DataFrame,
            y_test: pd.Series,
            cv_iterable: tp.Iterable,
            logger: Logger,
            metrics: tp.Dict[str, tp.Union[tp.Callable, str]],
            n_jobs=-1
    ):
        self.X_train = X_train
        self.y_train = y_train
        self.X_test = X_test
        self.y_test = y_test
        self._cv_iterable = cv_iterable
        self.logger = logger
        self._metrics = metrics
        self._n_jobs = n_jobs

    def score_test(self, estimator, metrics, run, test_data=None):
        """
        Computes scores for test data and logs them to given run
        :param estimator: fitted estimator
        :param metrics: metrics to compute
        :param run: run to log into
        :param test_data: optional argument if one wants to pass augmented test dataset
        :return: None
        """
        if test_data is None:
            test_data = self.X_test
        test_scores = _score(estimator, test_data, self.y_test, metrics)
        run.log_values({key + '_test': value for key, value in test_scores.items()})

    def score_cv(self, estimator, metrics, run):
        """
        computes scores on cross-validation
        :param estimator: estimator to fit
        :param metrics: metrics to compute
        :param run: run to log to
        :return: None
        """
        cross_val_results = sklearn.model_selection.cross_validate(
            estimator,
            self.X_train,
            self.y_train,
            cv=self._cv_iterable,
            n_jobs=self._n_jobs,
            scoring=metrics
        )
        for key, value in cross_val_results.items():
            if key.startswith('test_'):
                metric_name = key.split('_', maxsplit=1)[1]
                mean_score = np.mean(value)
                std_score = np.std(value)
                run.log_values(
                    {
                        metric_name + '_mean': mean_score,
                        metric_name + '_std': std_score
                    }
                )

    def generate_stacking_predictions(self, estimator, run):
        """
        generates predictions over cross-validation folds, then saves them as artifacts
        returns fitted estimator for convinience and les train overhead
        :param estimator: estimator to use
        :param run: run to log to
        :return: estimator fitted on train, stacking cross-val predictions, stacking test predictions
        """
        if hasattr(estimator, "predict_proba"):
            method = "predict_proba"
        elif hasattr(estimator, "decision_function"):
            method = "decision_function"
        else:
            method = "predict"
        cross_val_stacking_prediction = sklearn.model_selection.cross_val_predict(
            estimator,
            self.X_train,
            self.y_train,
            cv=self._cv_iterable,
            n_jobs=self._n_jobs,
            method=method
        )
        run.log_artifact(ExperimentHandler.stacking_prediction_filename,
                         lambda file: np.save(file, cross_val_stacking_prediction))
        estimator.fit(self.X_train, self.y_train)
        test_stacking_prediction = getattr(estimator, method)(self.X_test)
        run.log_artifact(ExperimentHandler.test_stacking_prediction_filename,
                         lambda file: np.save(file, test_stacking_prediction))
        return estimator, cross_val_stacking_prediction, test_stacking_prediction

    def get_metrics(self, estimator):
        """
        get callable metrics with estimator validation
        (e.g. estimator has predict_proba necessary for likelihood computation, etc)
        """
        return _check_multimetric_scoring(estimator, self._metrics)

    def run(self, estimator: sklearn.base.BaseEstimator, name=None):
        """
        perform run for given estimator
        :param estimator: estimator to use
        :param name: name of run for convinience and consitent logging
        :return: leaderboard with conducted run
        """
        metrics = self.get_metrics(estimator)
        with self.logger.run(name=name) as run:
            # compute predictions over cross-validation
            self.score_cv(estimator, metrics, run)
            fitted_on_train, _, _ = self.generate_stacking_predictions(estimator, run)
            self.score_test(fitted_on_train, metrics, run, test_data=self.X_test)
            return self.logger.leaderboard.loc[[run.name]]

    def get_stacking_predictions(self, run_names):
        """
        :param run_names: run names for which to extract stacking predictions for averaging and stacking
        :return: dataframe with predictions indexed by run names
        """
        train_dataframes = []
        test_dataframes = []
        for run_name in run_names:
            train_filename = self.logger.path / run_name / ExperimentHandler.stacking_prediction_filename
            train_dataframes.append(load_predictions_dataframe(filename=train_filename, column_prefix=run_name,
                                                               index=self.X_train.index))
            test_filename = self.logger.path / run_name / ExperimentHandler.test_stacking_prediction_filename
            test_dataframes.append(load_predictions_dataframe(filename=test_filename, column_prefix=run_name,
                                                              index=self.X_test.index))

        return pd.concat(train_dataframes, axis=1), pd.concat(test_dataframes, axis=1)
