import numpy as np
import math

N = 5

def cholesky(a):
    #check positive definition
    w, v = np.linalg.eig(np.array(a, dtype='float32'))
    for item in w:
        if item <= 0:
            return
    
    l=np.array([[0.0] * N] * N, dtype='float64')
    l[0, 0] = math.sqrt(a[0, 0])
    for j in range(1, N):
        l[j, 0] = a[j, 0] / l[0, 0]

        

    for i in range(1, N):
        for j in range(i, N):
            if i == j:
                l[i, i] = math.sqrt(a[i, i] - sum([l[i, p]**2 for p in range(0, i)]))
            else:
                l[j, i] = (a[j, i] - sum([l[i, p] * l[j, p] for p in range(0, i)])) / l[i,i]
    
    return l
    
# solve Ly = b
def find_y(l, b):
    y = np.zeros(N)
    y[0] = b[0] / l[0,0]
    for i in range(1, N):
        y[i] = (b[i] - np.dot(l[i][:i], y[:i])) / l[i, i]
    return y

#solve L.T * x = y
def find_x(l, y):
    l_t = l.T
    x = np.zeros(N)
    for i in range(N-1, -1, -1):
        x[i] = (y[i] - np.dot(l_t[i][i+1:], x[i+1:])) / l_t[i][i]
        
    return x


a = np.loadtxt('A.txt', delimiter=' ', dtype='float64')
b = np.loadtxt('B.txt', delimiter=' ', dtype='float64')

a_sim = a.T @ a
b_sim = a.T @ b
l = cholesky(a_sim)
y = find_y(l, b_sim)
x = find_x(l, y)

error = a @ x - b
error_sim = a_sim @ x - b_sim
print(error)

method_1_err = np.loadtxt('method_1_error.txt', delimiter = ' ', dtype='float64')
diff = error - method_1_err

np.savetxt(fname='x.txt', X=x)
np.savetxt(fname='comp_methods.txt', X=diff)
np.savetxt(fname='method_2_error.txt', X=error)
