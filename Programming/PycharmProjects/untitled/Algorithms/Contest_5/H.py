class Node:
    def __init__(self, value, left=None, right=None, parent=None, count=0):
        self.value = value
        self.left = left
        self.right = right
        self.parent = parent
        self.count = count

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

    def maximumis(self):
        if self.right is None:
            return self
        return self.right.maximumis()

    def tour(self):
        if self.isleaf():
            print(self.value)
            return
        if self.left is not None:
            self.left.tour()
        print(self.value)
        if self.right is not None:
            self.right.tour()

    def leaftour(self):
        if self.isleaf():
            print(self.value)
            return
        if self.left is not None:
            self.left.leaftour()
        if self.right is not None:
            self.right.leaftour()

    def divaricationtour(self):
        if self.isleaf():
            return
        if self.left is not None:
            self.left.divaricationtour()
        if self.left is not None and self.right is not None:
            print(self.value)
        if self.right is not None:
            self.right.divaricationtour()

    def branchtour(self):
        if self.isleaf():
            return
        if self.left is not None:
            self.left.branchtour()
        if (self.left is not None and self.right is None) or \
                (self.left is None and self.right is not None):
            print(self.value)
        if self.right is not None:
            self.right.branchtour()

    def count_(self, value):
        if value < self.value:
            if self.left is not None:
                return self.left.count_(value)
        elif value > self.value:
            if self.right is not None:
                return self.right.count_(value)
        else:
            return self

    def counttour(self):
        if self.isleaf():
            print(self.value, self.count)
            return
        if self.left is not None:
            self.left.counttour()
        print(self.value, self.count)
        if self.right is not None:
            self.right.counttour()


list1 = list(map(int, input().split()))
list1 = list1[:-1]
first = Node(list1[0], count=1)
list1.pop(0)
for i in list1:
    first.append(i)
for i in list1:
    c = first.count_(i)
    c.count += 1
first.counttour()
