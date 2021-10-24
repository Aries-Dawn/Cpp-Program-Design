import numpy as np

matrixA = np.loadtxt('./mat-A-32.txt')
matrixB = np.loadtxt('./mat-B-32.txt')
checking = np.loadtxt('./out32.txt')
result = np.dot(matrixA, matrixB)

diff = result - checking
print(checking)
print(result)
print(diff)
np.absolute(diff)
print(np.max(diff))
[rows, cols] = diff.shape
with open ('./out2048-diff.txt','w') as f:
    for i in range(rows):
        for j in range(cols):
            f.write("%.6f "%diff[i, j])
        f.write('\n')
