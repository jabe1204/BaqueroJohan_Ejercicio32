import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

data = np.loadtxt("datos.dat")*1E5
fig = plt.figure(figsize=(18,4))

x = np.linspace(0,1,np.shape(data)[1])
t = np.linspace(0,6,np.shape(data)[0])

plt.subplot(1,3,1)
plt.imshow(data, extent =[-1,1,1,0],aspect =2.0)
plt.xlabel("Posición")
plt.ylabel("$\psi$")
plt.colorbar()

#Editado y sacado de la solucion del profesor para el problema de difusión https://github.com/ComputoCienciasUniandes/FISI2028-201920/blob/master/ejercicios/29/plot.py
plt.subplot(1,3,2)
delta_t = 1.0/np.shape(data)[0]
for i in range(np.shape(data)[0]):
    if i%(np.shape(data)[0]//9) == 0:
        plt.plot(x, data[i,:],label="t={:.02f}".format(i*delta_t))
plt.legend(loc=1)
plt.xlabel("Posicion")
plt.ylabel("$\psi$")

plt.subplot(1,3,3)
plt.plot(t,data[:,np.shape(data)[1]//4], color = "black") ##Dividido en 4 para que se pueda ver bien el comportamiento
plt.xlabel("Tiempo")
plt.ylabel("$\psi$")
plt.savefig("EvolveA.png")
