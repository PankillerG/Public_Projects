def my_det(X):
    X.sort
    if len(X) != len(X[0]):
        raise ValueError
    else:
        length = len(X)
        for i in range(length):
                l1 = X[i][-i - 1]
                for j in range(i + 1, length):
                    l2 = X[j][-i - 1]
                    if l1 != 0:
                        for k in range(i, length):
                            X[j][-k - 1] = X[j][-k - 1] - (l2 * X[i][-k - 1]) / l1
    det = 1
    for i in range(len(X)):
        det = det * X[i][-i - 1]
    return det * (-1) **(len(X))