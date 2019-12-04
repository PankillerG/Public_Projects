number = set()
s = input()
s = s.replace(')', '')
s = s.replace('(', '')
s = s.replace('-', '')
s = s.replace('+', '')
if len(s) > 10:
    s = s[1:]
if len(s) > 7 and s[0:3] == '495':
    s = s[3:]
number.add(s)
for i in range(3):
    s = input()
    s = s.replace(')', '')
    s = s.replace('(', '')
    s = s.replace('-', '')
    s = s.replace('+', '')
    if len(s) > 10:
        s = s[1:]
    if len(s) > 7 and s[0:3] == '495':
        s = s[3:]
    if s in number:
        print('YES')
    else:
        print('NO')
