import numpy as np
import matplotlib.pyplot as plt
import pyarma as pa

A = pa.mat()
A.load("A_matrix.bin")

R = pa.mat()
R.load("R_matrix.bin")

An_vals = pa.mat()
An_vals.load("An_eigvals.bin")

An_vecs = pa.mat()
An_vecs.load("An_eigvecs.bin")

A = np.array(A)
R = np.array(R)

An_vals = np.array(An_vals)
An_vecs = np.array(An_vecs)

tol = 1e-8

eigenvals = np.zeros(len(A[:,0]))

for i in range(len(A[:,0])):
    for j in range(len(A[0,:])):
        if i==j:
            eigenvals[i] = A[i,j]
arr_min = np.argsort(eigenvals)[:3]

x = np.zeros(len(A[:,0])+1)

x[0] = 0
for i in range(1,len(A[:,0])+1):
    x[i] = x[i-1] + i*(1/len(A[:,0]))
x = np.append(x,x[-1]+1/len(A[:,0]))

print(An_vecs)
print(An_vecs[:,0])

y_arr1 = eigenvals[arr_min[0]]*R[:,arr_min[0]]
y_arr2 = eigenvals[arr_min[1]]*R[:,arr_min[1]]
y_arr3 = eigenvals[arr_min[2]]*R[:,arr_min[2]]
y_arr1 = np.insert(y_arr1,0,0)
y_arr2 = np.insert(y_arr2,0,0)
y_arr3 = np.insert(y_arr3,0,0)
y_arr1 = np.append(y_arr1,0)
y_arr2 = np.append(y_arr2,0)
y_arr3 = np.append(y_arr3,0)

an_y1 = An_vals[0][0]*An_vecs[:,0]
an_y2 = An_vals[1][0]*An_vecs[:,1]
an_y3 = An_vals[2][0]*An_vecs[:,2]

an_y1 = np.insert(an_y1,0,0)
an_y1 = np.append(an_y1,0)
an_y2 = np.insert(an_y2,0,0)
an_y2 = np.append(an_y2,0)
an_y3 = np.insert(an_y3,0,0)
an_y3 = np.append(an_y3,0)

plt.plot(x,y_arr1,label='Numerical v0')
plt.plot(x,y_arr2,label='Numerical v1')
plt.plot(x,y_arr3,label='Numerical v2')

plt.plot(x,an_y1,label='Analytical v0')
plt.plot(x,an_y2,label='Analytical v1')
plt.plot(x,an_y3,label='Analytical v2')
plt.xlabel("$\hat{x}$")
plt.ylabel("$u(\hat{x})$")
plt.legend()
plt.savefig("plot_n10.pdf")
plt.show()
