from copy import deepcopy
from sys import stdin

class MatrixError(BaseException):
    def __init__(self, matrix1, matrix2):
        self.matrix1 = matrix1
        self.matrix2 = matrix2

class Matrix:
    def __init__(self, list_of_lists):
        self.matrix = deepcopy(list_of_lists)

    def __str__(self):
        string = ''
        for row in self.matrix:
            string += '\t'.join(map(str, row))
            string += '\n'
        return string[:-1]

    def size(self):
        return len(self.matrix), len(self.matrix[0])

    def __add__(self, other):
        sum_ = Matrix(self.matrix)
        size = self.size()
        if self.size() != other.size():
            raise MatrixError(self, other)
        for row_index in range(size[0]):
            for row in range(size[1]):
                sum_.matrix[row_index][row] += other.matrix[row_index][row]
        return sum_

    def __mul__(self, other):
        mul = Matrix(self.matrix)
        size = self.size()
        for row_index in range(size[0]):
            for row in range(size[1]):
                mul.matrix[row_index][row] *= other
        return mul
    __rmul__ = __mul__

    def transpose(self):
        size = self.size()
        for i in range(size[0]):
            for j in range(i, size[1]):
                c = self.matrix[i][j]
                self.matrix[i][j] = self.matrix[j][i]
                self.matrix[j][i] = c

    def transposed(self):
        return map(list, zip(*self.matrix))


#exec(stdin.read())

m = Matrix([[10, 10], [0, 0], [1, 1]])
print(m)
m1 = m.transposed()
print(m)
print(m1)
