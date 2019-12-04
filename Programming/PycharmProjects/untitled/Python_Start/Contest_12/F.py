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
        if isinstance(other, int) or isinstance(other, float):
            for row_index in range(size[0]):
                for row in range(size[1]):
                    mul.matrix[row_index][row] *= other
            return mul
        elif isinstance(other, Matrix):
            if self.size()[1] == other.size()[0]:
                mul = Matrix(
                    list(
                        map(
                            lambda x: list(
                                map(
                                    lambda y: sum(
                                        map(
                                            lambda z: z[0] * z[1],
                                            zip(x, y)
                                        )
                                    ),
                                    zip(*other.matrix)
                                )
                            ),
                            self.matrix
                        )
                    )
                )
                return mul
            else:
                raise MatrixError(self, other)
    __rmul__ = __mul__

    def transpose(self):
        new = []
        localist = []
        size = self.size()
        for i in range(size[1]):
            for j in range(size[0]):
                localist.append(self.matrix[j][i])
            new.append(localist)
            localist = []
        self.matrix = new
        new = Matrix(new)
        return new

    def transposed(self):
        return Matrix(list(map(list, zip(*self.matrix))))


class SquareMatrix(Matrix):
    def __pow__(self, power):
        new = []
        localList = []
        if power == 0:
            for i in range(self.size()[0]):
                for j in range(self.size()[1]):
                    if i == j:
                        localList.append(1)
                    else:
                        localList.append(0)
                new.append(localList)
                localList = []
            return Matrix(new)
        elif power == 1:
            return self
        else:
            r = self ** (power // 2)
            return self ** (power % 2) * r * r
            #return self * self ** (power - 1)


#exec(stdin.read())

m = SquareMatrix([[1, 1, 0, 0, 0, 0],
                  [0, 1, 1, 0, 0, 0],
                  [0, 0, 1, 1, 0, 0],
                  [0, 0, 0, 1, 1, 0],
                  [0, 0, 0, 0, 1, 1],
                  [0, 0, 0, 0, 0, 1]]
                )
print(m)
print('----------')
print(m ** 1)
print('----------')
print(m ** 2)
print('----------')
print(m ** 3)
print('----------')
print(m ** 4)
print('----------')
print(m ** 5)
