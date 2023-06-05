import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Load the input and output data
data1 = np.loadtxt(fname='../cmake-build-debug/Tree_search.txt', usecols=[0, 1, 2])

# Define the function to fit to the data
def my_function(x, a, b):
    return a * (np.log(x)) + b

x = data1[:, 0]
y = data1[:, 1]
std_dev = data1[:, 2]
# Fit a curve to the data using standard deviation values
popt,pcov = curve_fit(my_function, x, y, sigma=std_dev)
plt.errorbar(x, y, yerr=std_dev, fmt='r+', label='mätvärde')
#plt.plot(x,y,'bo')

# Generate the fitted curve using the optimized function parameters
curve = my_function(x, *popt)
plt.ylim(bottom=0)
plt.xlim(left=0)
plt.plot(x, curve, label=' Binary_with_tree')

plt.xlabel('N elements')
plt.ylabel('t[µs]')
plt.legend()
plt.show()