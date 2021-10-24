import numpy as np

matrixA = np.loadtxt('./out2048.txt')
matrixB = np.loadtxt('./out2048-O.txt')
# checking = np.loadtxt('./out32.txt')
# result = np.dot(matrixA, matrixB)

diff = matrixA - matrixB
np.absolute(diff)
# print(checking)
# print(result)
# print(diff)
np.absolute(diff)
print(np.max(diff))
# [rows, cols] = diff.shape
# with open ('./out2048-diff.txt','w') as f:
#     for i in range(rows):
#         for j in range(cols):
#             f.write("%.6f "%diff[i, j])
#         f.write('\n')
