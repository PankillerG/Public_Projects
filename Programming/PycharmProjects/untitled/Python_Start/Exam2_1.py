def Election(x, y, z):
        sum_ = x + y + z
        if sum_ >= 2:
            return True
        else:
            return False


x, y, z = map(int, input().split())
print(int(Election(x, y, z)))
