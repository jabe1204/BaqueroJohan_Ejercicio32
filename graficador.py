import numpy as np
import matplotlib.pylab as plt

data = np.loadtxt("datos.dat")

plt.subplot(1,3,1)
plt.imshow(data,aspect = "auto")
plt.title("Nx = 30")
plt.xlabel("Posición")
plt.ylabel("Tiempo")

plt.subplot(1,3,2)
plt.subplot(1,3,3)
plt.savefig("EvolveA.png")

