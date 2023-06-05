import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Load the input and output data
data1 = np.loadtxt(fname='../cmake-build-debug/binary_search.txt', usecols=[0, 1, 2])

# Define the function to fit to the data
def my_function(x, a, b):
    return a * (np.log(x)) + b

x = data1[:, 0]
y = data1[:, 1]
std_dev = data1[:, 2]

# Fit a curve to the data using standard deviation values
popt, pcov = curve_fit(my_function, x, y, sigma=std_dev)

# Generate the fitted curve using the optimized function parameters
curve = my_function(x, *popt)

# Plot the data and the fitted curve
fig, ax = plt.subplots()
ax.errorbar(x, y, yerr=std_dev, fmt='r+', label='mätvärde')
ax.plot(x, curve, label='MY Code')

# Set the x-axis and y-axis limits to start from zero
ax.set_xlim(left=0)
ax.set_ylim(bottom=0)

# Set the labels for the x-axis and y-axis
ax.set_xlabel('N elements')
ax.set_ylabel('t[µs]')

# Show the legend
ax.legend()

# Show the plot
plt.show()
