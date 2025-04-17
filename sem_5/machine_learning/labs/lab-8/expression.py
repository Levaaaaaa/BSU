import numpy as np

def roc_auc(probabilities, y_true):
    probabilities = np.array(probabilities)
    y_true = np.array(y_true)

    n_pos = np.sum(y_true == 1)
    n_neg = np.sum(y_true == 0)
    if n_pos == 0 or n_neg == 0:
        return 0.0
    
    sorted_ind = np.argsort(probabilities)
    sorted_prob = probabilities[sorted_ind]
    ranks = np.zeros(len(probabilities))

    i = 0
    while i < len(probabilities):
        start = i
        val = sorted_prob[i]
        while i + 1 < len(probabilities) and sorted_prob[i+1] == val:
            i+=1
        end = i
        avg = (start + end)/2 + 1
        ranks[sorted_ind[start:end + 1]] = avg
        i+=1

    sum = np.sum(ranks[y_true == 1])
    auc = (sum - n_pos*(n_pos + 1)/2)/(n_pos * n_neg)
    return auc