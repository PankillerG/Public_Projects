from copy import deepcopy

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

    '''def __add__(self, other):
        sum_ = Matrix(self.matrix)
        size = self.size()
        for row_index in range(size[0]):
            for n_index in range(size[1]):
                sum_.matrix[row_index][n_index] += other.matrix[row_index][n_index]'''


'''a = Matrix([[1, 2, 3], [4, 5, 6]])
b = Matrix([[1, 0, 0], [0, 1, 0]])
c = a + b
print(a)
print(b)
print(c)'''
