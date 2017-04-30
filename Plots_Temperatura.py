import numpy as np
import matplotlib.pyplot as plt


fijasCaso1_t0 = np.loadtxt("fijasCaso1_t0.txt")
t_fijasCaso1_t0 = np.zeros((100,100))

fijasCaso1_t100 = np.loadtxt("fijasCaso1_t100.txt")
t_fijasCaso1_t100 = np.zeros((100,100))

fijasCaso1_t2500 = np.loadtxt("fijasCaso1_t2500.txt")
t_fijasCaso1_t2500 = np.zeros((100,100))

fijasCaso2_t0 = np.loadtxt("fijasCaso2_t0.txt")
t_fijasCaso2_t0 = np.zeros((100,100))

fijasCaso2_t100 = np.loadtxt("fijasCaso2_t100.txt")
t_fijasCaso2_t100 = np.zeros((100,100))

fijasCaso2_t2500 = np.loadtxt("fijasCaso2_t2500.txt")
t_fijasCaso2_t2500 = np.zeros((100,100))


def linealizar(matriz, data):
	k=0
	for i in range(100):
		for j in range(100):
			matriz[j][i]= data[k]
			k+=1

linealizar(t_fijasCaso1_t0, fijasCaso1_t0)
linealizar(t_fijasCaso1_t2500, fijasCaso1_t2500)
linealizar(t_fijasCaso1_t100, fijasCaso1_t100)
linealizar(t_fijasCaso2_t0, fijasCaso2_t0)
linealizar(t_fijasCaso2_t2500, fijasCaso2_t2500)
linealizar(t_fijasCaso2_t100, fijasCaso2_t100)

plt.imshow(t_fijasCaso1_t0)
plt.title("Caso 1 en condiciones de frontera fijas a t=0")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("fijasCaso1_t0.pdf")
plt.close()

plt.imshow(t_fijasCaso1_t100)
plt.title("Caso 1 en condiciones de frontera fijas a t=100")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("fijasCaso1_t100.pdf")
plt.close()

plt.imshow(t_fijasCaso1_t2500)
plt.title("Caso 1 en condiciones de frontera fijas a t=2500")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("fijasCaso1_t2500.pdf")
plt.close()

plt.imshow(t_fijasCaso2_t0)
plt.title("Caso 2 en condiciones de frontera fijas a t=0")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("fijasCaso2_t0.pdf")
plt.close()

plt.imshow(t_fijasCaso2_t100)
plt.title("Caso 2 en condiciones de frontera fijas a t=100")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("fijasCaso2_t100.pdf")
plt.close()

plt.imshow(t_fijasCaso2_t2500)
plt.title("Caso 2 en condiciones de frontera fijas a t=2500")
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.savefig("fijasCaso2_t2500.pdf")
plt.close()

fijasCaso1_mean = np.loadtxt("fijasCaso1_mean.txt")
fijasCaso2_mean = np.loadtxt("fijasCaso2_mean.txt")

tiempo = fijasCaso1_mean[:,0]
f1_mean = fijasCaso1_mean[:,1]
f2_mean = fijasCaso2_mean[:,1]


plt.figure()
plt.plot(tiempo, fijasCaso1_mean)
plt.xlabel("Tiempo")
plt.ylabel("Temperatura")
plt.savefig("PromedioCasoFijasCaso1.pdf")
plt.close()

plt.figure()
plt.plot(tiempo, fijasCaso2_mean)
plt.xlabel("Tiempo")
plt.ylabel("Temperatura")
plt.savefig("PromedioFijasCaso2.pdf")
plt.close()





