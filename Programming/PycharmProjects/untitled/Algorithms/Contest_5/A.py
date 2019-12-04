class Node:
    def __init__(self, value, left=None, right=None, parent=None):
        self.value = value
        self.left = left
        self.right = right
        self.parent = parent

    def isleaf(self):
        if self.left is None and self.right is None:
            return True
        return False

    def deepis(self):
        if not self.isleaf():
            later = list()
            if self.left is not None:
                later.append(self.left)
            if self.right is not None:
                later.append(self.right)
            return max(map(lambda key: key.deepis(), later)) + 1
        return 1

    def append(self, value):
        if value < self.value:
            if self.left is not None:
                self.left.append(value)
                return
            self.left = Node(value, parent=self)
        elif value > self.value:
            if self.right is not None:
                self.right.append(value)
                return
            self.right = Node(value, parent=self)


list1 = list(map(int, input().split()))
list1 = list1[:-1]
first = Node(list1[0])
list1.pop(0)
for i in list1:
    first.append(i)
print(first.deepis())
