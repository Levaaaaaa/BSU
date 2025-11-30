#tuzikov #source #onion-net-2

# Идея
__OnionNet-2__ - двумерная сверточная нейронная сеть для прогнозирования энергии связывания комплекса "[[receptor|мишень]] - [[ligand|лиганд]]"

## Таргет - энергия связывания
## Обучение
Модель обучена на датасете _[PDBbind](http://www.pdbbind-cn.org/)_ 

## Тестирование
Протестирована с помощью _сравнительной оценки [[scoring-function|оценочных функций]] (CASF)_

Когда общее количество оболочек составляло 62, __OnionNet-2__ достигла наилучших результатов с коэффициентом корреляции Пирсона ( _R_ ), достигающим 0,864, и среднеквадратичной ошибкой (RMSE) 1,164.

Для оценки оценочной способности модели использовали коэффициент корреляции Пирсона R, среднеквадратичное отклонение (RMSE) и стандартное отклонение (SD)

 Использовали модель CNN, основанную на двумерной свёртке, для изучения взаимосвязи между контактными признаками и __таргетом__ . Модель была построена с использованием пакета Keras в TensorFlow [(Abadi et al., 2016)](https://www.frontiersin.org/journals/chemistry/articles/10.3389/fchem.2021.753002/full#B1)

## Исходный код
https://github.com/zchwang/OnionNet-2/

python scoring/predict.py -rec_fpath samples\1a30\1a30_protein.pdb -lig_fpath samples\1a30\1a30_ligand.pdb -shape 84,124,1 -scaler models\train_scaler.scaler -model models\62shell_saved-model.h5 -shells 62 -out_fpath $out_fpath

```
conda install tensorflow==2.3 pandas==1.3.4 scikit-learn==0.22.1 joblib==1.0.1 numpy==1.18.5 scipy==1.4.1
```