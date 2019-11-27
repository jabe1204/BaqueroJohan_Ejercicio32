import numpy as np
import matplotlib.pylab as plt

data = np.loadtxt("datos.dat")
plt.figure(figsize=(12,4))
plt.subplot(1,3,1)
plt.imshow(data,aspect = "auto")
plt.title("Nx = 30")
plt.xlabel("Posición")
plt.ylabel("Tiempo")

plt.subplot(1,3,2)
size = np.shape(data)
Nt = size[0]
Nx = size[1]
dt = 1/Nt
x =np.linspace(-1,1,Nx)
for i in range(Nt):
        plt.plot(x, data[i,:], alpha=(i+1)/Nt, color='black', label="t={:.02f}".format(i*dt))
plt.legend(loc=4)
plt.xlabel("Posición")
plt.ylabel("$\psi$")
plt.subplot(1,3,3)

plt.savefig("EvolveA.png")

