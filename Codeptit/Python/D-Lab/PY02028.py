n = input()
a = input().split()

def snt(n):
    if n < 2:
        return False
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            return False
    return True

b = []
c = []

for i in range(0, len(a)):
    if snt(int(a[i])):
        b.append(i)
        c.append(a[i])
c.sort(key=int)
d = 0
for i in b:
    a[i] = c[d]
    d += 1
    
for i in a:
    print(i, end=' ')