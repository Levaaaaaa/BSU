import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Параметры
l = 1
N = 100 # число членов суммы по k

# Сетка
x = np.linspace(0, l, 200)
t = np.linspace(0, 5, 200)
X, T = np.meshgrid(x, t)

# Основная сумма
U = np.zeros_like(X)

for k in range(1, N + 1):
    coef = (2 * l * np.cos(np.pi * k)) / ((np.pi * k)**2)
    U += coef * np.cos(np.pi * k * T / l) * np.cos(np.pi * k * X / l)

# Добавим оставшиеся члены
U += -((T + 1) / l) * X**2 + T * X

# Визуализация
fig = plt.figure(figsize=(12, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, T, U, cmap='inferno')

ax.set_title("u(x, t)")
ax.set_xlabel("x")
ax.set_ylabel("t")
ax.set_zlabel("u(x, t)")

plt.tight_layout()
plt.savefig("graph3.png", dpi=300)
plt.show()
