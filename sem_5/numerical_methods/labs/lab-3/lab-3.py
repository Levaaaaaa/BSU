from collections.abc import Sequence, MutableSequence
import numpy as np

def Jacobi(
        A,
        b,
        eps: float = 0.001,
        x_init = None) -> list[float]:

    def sum(a, x, j: int) -> float:
        S: float = 0
        for i, (m, y) in enumerate(zip(a, x)):
            if i != j:
                S += m*y
        return S

    def norm(x, y) -> float:
        return max((abs(x0-y0) for x0, y0 in zip(x, y)))

    if x_init is None:
        y = [a/A[i][i] for i, a in enumerate(b)]
    else:
        y = x_init.copy()

    x: list[float] = [-(sum(a, y, i) - b[i])/A[i][i]
                      for i, a in enumerate(A)]

    iterations_count = 0
    while norm(y, x) > eps:
        for i, elem in enumerate(x):
            y[i] = elem
        for i, a in enumerate(A):
            x[i] = -(sum(a, y, i) - b[i])/A[i][i]
        iterations_count += 1
    return x, iterations_count

def ldr_decomposition(A):
    # Инициализация матриц L, D и R
    n = A.shape[0]
    L = np.zeros_like(A, dtype=np.float64)
    D = np.zeros_like(A, dtype=np.float64)
    R = np.zeros_like(A, dtype=np.float64)

    for i in range(n):
        for j in range(n):
            if i == j:  # Если элемент на главной диагонали
                D[i, j] = A[i, j]
                #L[i, j] = 0  # 1 на главной диагонали L
            elif i > j:  # Если элемент ниже главной диагонали
                L[i, j] = A[i, j]
            elif i < j:  # Если элемент выше главной диагонали
                R[i, j] = A[i, j]

    return L, D, R

def diagonal_dominant_coefficient(A):
    diag = []
    notdiag = []
    for i in range(len(A)):
        diag.append(np.abs(A[i,i]))
        notdiag.append(sum([np.abs(A[i,j]) for j in range(len(A[i])) if i != j]))
        if diag[i] < notdiag[i]:
            return False
    np.savetxt(fname='diag_dominant_res.txt', X=list(zip(diag, notdiag)))
    return True

A = np.loadtxt(fname='A.txt', dtype=np.float64)

print(diagonal_dominant_coefficient(A))
B = np.loadtxt('B.txt', dtype=np.float64)

e = np.eye(N=A.shape[0])
L, D, R = ldr_decomposition(A)
another_b = -np.linalg.inv(D) @ (L + R)
w, v = np.linalg.eig(another_b)
with open('spec_radius.txt', 'w') as f:
    f.write(str(np.max(np.abs(w))))
norm_b = np.linalg.norm(another_b, np.inf)
print(norm_b)


X, iterations_count = Jacobi(A, B, eps=1e-5, x_init=B)

x_np = np.array(X)
error = A @ x_np - B
print(error)

np.savetxt(X=error, fname='error.txt')
np.savetxt(X=x_np, fname='x_result.txt')
with open('iterations.txt', 'w') as file:
    file.write(str(iterations_count))