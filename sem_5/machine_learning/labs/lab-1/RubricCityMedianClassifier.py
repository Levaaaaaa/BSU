import numpy as np
import pandas as pd
from sklearn.base import ClassifierMixin

class RubricCityMedianClassifier(ClassifierMixin):
  def __init__(self):
    self.mrubs_city_df = None

  def fit(self, X=None, y=None):
    table = pd.concat([X[['city', 'modified_rubrics']], y], axis=1)
    self.mrubs_city_df = table
    return self

  def f(self, row):
    city_filter = (self.mrubs_city_df['city'] == row.loc['city'])
    rubrics_filter = (self.mrubs_city_df['modified_rubrics'] == row.loc['modified_rubrics'])
    return self.mrubs_city_df[city_filter & rubrics_filter].iloc[:, -1].median()

  def predict(self, X=None):
    return X[['city', 'modified_rubrics']].apply(self.f, axis=1)