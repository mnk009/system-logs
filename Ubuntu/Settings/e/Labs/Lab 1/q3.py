import numpy as np

# Printing the common items from two numpy arrays also printing the position of the common elements
# removing the common items and printing the remaining elements of the two numpy arrays?

a1 = np.array([12, 43, 53, 75, 89, 74])
a2 = np.array([13, 47, 19, 95, 43, 89])

for i in a1:
    if i in a2:
        print("This number is common in both the numpy arrays:", i)
        b = list(a1).index(i)
        print("The number is present in a1 array in the position:", b+1)
        b = list(a2).index(i)
        print("The number is present in a2 array in the position:", b+1)
        b = list(a1)
        b.remove(i)
        a1 = np.array(b)
        print("The array after removing %d is " % i, a1)
        b = list(a2)
        b.remove(i)
        a2 = np.array(b)
        print("The array after removing %d is " % i, a2)
        print("")
