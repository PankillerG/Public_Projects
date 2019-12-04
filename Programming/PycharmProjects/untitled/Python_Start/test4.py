def gcd(a, b):
    if a == b:
        return a
    elif a != 0 and b != 0:
        if a > b:
            return gcd(a % b, b)
        else:
            return gcd(a, b % a)
    else:
        return a + b


a = int(input())
b = int(input())
print(gcd(a, b))

