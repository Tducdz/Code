def ucln(a, b):
    if b == 0: return a
    return ucln(b, a % b)
a = input().split()
n = int(a[0])
k = int(a[1])
dem = 0
for i in range(10 ** (k - 1), 10 ** k - 1):
    if (ucln(i, n) == 1):
        dem += 1
        if (dem % 10 == 0):
            print(i)
        else:
            print(i, end=' ')
        