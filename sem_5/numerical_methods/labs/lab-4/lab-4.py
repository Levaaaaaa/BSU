import numpy as np

def simple_iteration(A, b, x0, t, tol=1e-5, max_iter=1000):
    """
    Решение СЛАУ методом простой итерации.
    
    Параметры:
        A (numpy.ndarray): Матрица коэффициентов.
        b (numpy.ndarray): Вектор свободных членов.
        x0 (numpy.ndarray): Начальное приближение.
        t (float): Параметр итераций.
        tol (float): Погрешность.
        max_iter (int): Максимальное число итераций.
        
    Возвращает:
        x (numpy.ndarray): Приближённое решение.
        n_iter (int): Число выполненных итераций.
    """
    x = x0
    for n_iter in range(max_iter):
        # Вычисление нового приближения
        x_new = x - t * (A @ x - b)
        # Проверка критерия остановки
        if np.max(np.abs(x_new - x)) < tol: #np.linalg.norm(x_new - x, ord=np.inf) < tol:
            return x_new, n_iter + 1
        x = x_new
    raise ValueError("Метод не сошёлся за заданное число итераций.")

def is_positive_definite_eigenvalues(A):
    """Проверка положительной определённости матрицы через собственные значения."""
    eigenvalues = np.linalg.eigvals(A)  # Вычисление собственных значений
    return np.all(eigenvalues > 0)      # Проверка, что все значения положительны

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

# Пример матрицы A и вектора b
A = np.loadtxt(fname='A.txt')
A_t = np.transpose(A)
A = A_t @ A
b = np.loadtxt(fname='B.txt')
b = A_t @ b

w,_ = np.linalg.eig(A)
t = 2 / np.abs((np.max(np.real(w)) + np.min(np.real(w))))  # Параметр
x0 = b

another_b = np.eye(A.shape[0], A.shape[1]) - t * A
diagonal_dominant_coefficient(another_b)
w, v = np.linalg.eig(another_b)
with open('spec_radius.txt', 'w') as f:
    f.write(str(np.max(np.abs(w))))

# Решение СЛАУ
x, iterations = simple_iteration(A, b, x0, t)

error = (A @ x) - b
np.savetxt(fname='x_res.txt', X=x)
np.savetxt(fname='error.txt', X=error)
with open('iterations.txt', 'w') as f:
    f.write(str(iterations))

print(f"Решение: {x}")
print(f"Число итераций: {iterations}")
