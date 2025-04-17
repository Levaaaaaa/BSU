import numpy as np

from tabulate import tabulate

from sympy import Symbol, solve

A = np.loadtxt(fname="A.txt", dtype=float)
print(f"A:\n{tabulate(A, tablefmt='grid', floatfmt='.4f')}")

A = A.T @ A
print(f"A.T @ A:\n {tabulate(A, tablefmt='grid', floatfmt='.4f')}")

def format_print(X, p, r1, r2, eigenvalue, eigenvector, r_eigenvalue, r_eigenvector, c=None):

    p *= -1

    x = [f"x^{i}" if i != 1 else "x" for i in range(5, 0, -1)]

    polynom = "p(x)="

    for i, j in zip(x, p):

        polynom += i

        polynom += f" - {-round(j, 3)}" if np.sign(j) == -1 else f" + {round(j, 3)}"

    print(f'1)Frobenius normal form:\n{tabulate(X, tablefmt="grid", floatfmt=".3f")}\n',\

        f'2)Characteristic polynomial:\n{polynom}\n',\

        f'3)r1 = p1 - SpA = {r1:.3e}\n',\

        f'4)r2 = p5 - detA = {r2:.3e}\n',\

        f'5)min eigenvalue: {eigenvalue}\n',\

        f'6)eigenvector:\n{tabulate([eigenvector], tablefmt="grid", floatfmt=".5f")}\n',\

        f'7)r of eigenvalue: {r_eigenvalue}\n',\

        f'8)r of eigenvector:\n{tabulate([r_eigenvector], tablefmt="grid", floatfmt=".3e")}\n',\

          "" if c is None else f'9)count of iterations: {c}')

def format_print_danilevsky(eigenvalue, eigenvector, r_eigenvalue, r_eigenvector, c=None):
    print(
        '\nDanilevsky eigenvector:\n',\
        f'5)min eigenvalue: {eigenvalue}\n',\

        f'6)eigenvector:\n{tabulate([eigenvector], tablefmt="grid", floatfmt=".5f")}\n',\

        f'7)r of eigenvalue: {r_eigenvalue}\n',\

        f'8)r of eigenvector:\n{tabulate([r_eigenvector], tablefmt="grid", floatfmt=".3e")}\n',

          "" if c is None else f'9)count of iterations: {c}'
    )
    

def danilevsky_method(A: np.ndarray):

    X = A.copy()

    n = X.shape[0]

    s = np.eye(n)
    n -= 1

    for i in np.arange(n):

        ones_left = np.eye(n+1)

        ones_left[n-1-i] = X[n-i]

        ones_right = ones_left.copy()

        ones_right[n-1-i] /= -X[n-i, n-1-i]

        ones_right[n-1-i, n-1-i] = 1 / X[n-i, n-1-i]

        X = ones_left @ X @ ones_right

        s = s @ ones_right

    p = X[0]

    r1 = p[0] - np.trace(A)

    detA = np.linalg.det(A)

    r2 = p[n] - detA

    return X, r1, r2, s, p


#find min eigenvalue
def power_iteration(A: np.ndarray, num_iter: int=1000, tol: float=1e-5):

    n = A.shape[0]

    u = np.zeros(n)

    u[0] = 1

    prev_eigenvalue = 0 

    c = 0

    u_prev = u
    for k in range(1, num_iter + 1):

        c += 1

        #v = np.linalg.solve(A, u)
        v = A @ u
        v_norm = np.linalg.norm(v, np.inf)

        u = v / v_norm
        eigenvalue = (v @ u_prev) / (u_prev @ u_prev) 

        if abs(eigenvalue - prev_eigenvalue) < tol:
            break
        prev_eigenvalue = eigenvalue
        u_prev = u
        
    return eigenvalue, u, c


def danilevsky_power_method(A: np.ndarray, type_eigenvector='danilevsky'):

#    inv_A = np.linalg.inv(A)

    X = np.linalg.inv(A)

    n = X.shape[0]

    X, r1, r2, s, p = danilevsky_method(X)

    eigenvalue, u, c = power_iteration(X)

    r_eigenvalue = np.sum([p[n-1-i] * (eigenvalue ** i) for i in range(n)]) - eigenvalue ** (n)

    if type_eigenvector == 'danilevsky':

        y = np.array([eigenvalue ** i for i in np.arange(n-1, -1, -1)])

        eigenvector = s @ y

        r_eigenvector = X @ eigenvector - eigenvalue * eigenvector

    else:

        r_eigenvector = X @ u - eigenvalue * u
        eigenvector = u

    return X, p, r1, r2, c, 1/eigenvalue, eigenvector, r_eigenvalue, r_eigenvector


X, p, r1, r2, c, eigenvalue, eigenvector, r_eigenvalue, r_eigenvector = danilevsky_power_method(A)
format_print(X, p, r1, r2, eigenvalue, eigenvector, r_eigenvalue, r_eigenvector, c)

_, _, _, _, c, eigenvalue, eigenvector, r_eigenvalue, r_eigenvector = danilevsky_power_method(A, type_eigenvector='')
format_print_danilevsky(eigenvalue, eigenvector, r_eigenvalue, r_eigenvector, c)

eigs = np.sort(np.linalg.eig(A).eigenvalues)
print(f'True eigenvalues: {eigs}')
print(f'|lambda_1 / lambda_2| = {abs(eigs[-2])/abs(eigs[-1])}')