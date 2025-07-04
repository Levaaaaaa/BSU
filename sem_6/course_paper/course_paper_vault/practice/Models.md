Проверим и сравним качество моделей разных архитектур на задаче предсказания свойств малых молекул

| №   | Название модели                                | Архитектура               | Описание                                  |
| --- | ---------------------------------------------- | ------------------------- | ----------------------------------------- |
| 1 + | **ChemBERTa**                                  | Табличная ML              | Gradient boosting на фингерпринтах        |
| 2 + | **GCN (GraphConvModel из DeepChem)**           | Графовая (GCN)            | Работает напрямую с молекулярным графом   |
| 3   | **MPNN (Message Passing Neural Network)**      | Графовая (MPNN)           | Учитывает сообщение между атомами         |
| 4   | **AttentiveFP**                                | Графовая (Attention MPNN) | Более сложная графовая модель с вниманием |
| 5   | **SchNet**                                     | Граф + 3D                 | Использует атомные координаты (если есть) |
| 6   | **SMILES Transformer (например, SMILES-BERT)** | SMILES трансформер        | Альтернатива ChemBERTa для SMILES         |
### Random Forest
Стандартный sklearn.RandomForestRegressor, обученный на выборке из [[Dataset|датасета]].
### Chem BERTa
- Табличная ML
- Gradient boosting на фингерпринтах
- реализация - transformers.RobertaForSequenceClassification
### GCN
- Графовая (GCN)
- Работает напрямую с молекулярным графом
- реализация - dgllife.model.GCNPredictor
- необходимо предобучить на [[Dataset|датасете]]
