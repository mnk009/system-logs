import numpy as np

# Generating a random 4*4 matrix by using numpy and also finding minimum and the maximum values

x = np.random.random((4, 4))
print("Original Array:")
print(x)
xmin, xmax = x.min(), x.max()
print("Minimum and Maximum Values:")
print(xmin, xmax)
