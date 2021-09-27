import numpy as np
import matplotlib.pyplot as plt


data_y = np.array([6,35,139,187,206,266,289,351,631,2610,5821,16098])
data_x = np.array([4,6,10,11,12,13,14,15,20,40,60,100])
x_arr = np.linspace(0,100,1000)

new_data_y = np.array([15,44,139,169,216,244,295,343,634,2668,6177,17498])
plt.plot(data_x,data_y)
plt.plot(data_x,new_data_y)

plt.plot(x_arr,x_arr**(2.1),'r--')
plt.show()
