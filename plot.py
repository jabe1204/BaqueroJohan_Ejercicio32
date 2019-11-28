import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

data = np.loadtxt("datos.dat")
fig = plt.figure(figsize=(15,4))

dx = np.shape(data)[1]
dt = np.shape(data)[0]
x = np.linspace(0,1,dx)
t = np.linspace(0,6,dt)
X,T = np.meshgrid(x,t)


ax = fig.add_subplot(121, projection="3d")
surf = ax.plot_surface(X, T, data, cmap=cm.coolwarm)
plt.xlabel("Posición")
plt.ylabel("Tiempo")
ax.set_zlim3d(-1, 1)
ax.view_init(20, 20)
fig.colorbar(surf)

plt.subplot(1,2,2)
plt.plot(x, data[0,:], label="tiempo inicial")
plt.plot(x, data[-1,:], label="tiempo final")
plt.xlabel("Posicion")
plt.ylabel("Desplazamiento")
plt.legend()
plt.savefig("onda.png", bbox_inches="tight")
