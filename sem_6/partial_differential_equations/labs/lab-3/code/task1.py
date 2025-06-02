import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

g = 9.8
l = 1
a = 1

x = np.linspace(0, 2 * l, 200)
t = np.linspace(0, 5, 200)
X, T = np.meshgrid(x, t)

U = np.zeros_like(X)
for k in range(1, 101):
    coef = (16 * g * l**2) / (a**2 * (np.pi + 2*k)**3)
    omega_k = a * (np.pi + 2*k) / (2 * l)
    U += coef * np.sin(omega_k * T) * np.sin((np.pi - 2*k) * X / (2 * l))

fig = plt.figure(figsize=(12, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, T, U, cmap='viridis')

ax.set_title('u(x, t)')
ax.set_xlabel('x')
ax.set_ylabel('t')
ax.set_zlabel('u(x, t)')

plt.savefig("graph1.png", dpi=300)
plt.show()
