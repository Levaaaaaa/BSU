import numpy as np
import matplotlib.pyplot as plt

from mpl_toolkits.mplot3d import Axes3D

# Параметры
a = 1
l = 1
e = 1
N = 100  # Кол-во членов суммы

# Сетка значений
x = np.linspace(0, e, 200)
t = np.linspace(0.1, 5, 200)  # t > 0, чтобы избежать деления на 0
X, T = np.meshgrid(x, t)

# Первый член функции
term1 = (1 - l / (2 * a) + ((l / (2 * a * T))**2) * np.sin(2 * a * np.pi * T / e) * np.cos(a * np.pi * T / e) -
         0.5 * (l / (a * T))**2 * np.sin(a * np.pi * T / e)**3) * np.sin(np.pi * X / e)

# Второй член — сумма по k
term2 = np.zeros_like(X)

for k in range(1, N + 1):
    denom = k * np.cos(k * l)
    # чтобы избежать деления на ноль, если cos(kl)=0
    if np.any(np.isclose(denom, 0)):
        continue
    term2 += (-2 * np.cos(k * l) / denom) * np.cos(a * k * np.pi * T / e) + np.sin((k * l / e) * X)

# Общая функция
U = term1 + term2

# Визуализация
fig = plt.figure(figsize=(12, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, T, U, cmap='plasma')

ax.set_title("u(x, t)")
ax.set_xlabel("x")
ax.set_ylabel("t")
ax.set_zlabel("u(x, t)")

plt.tight_layout()
plt.savefig("graph2.png", dpi=300)
plt.show()
