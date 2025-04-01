from math import gcd

a = input().split()
l = int(a[0])
r = int(a[1])

for i in range(l, r - 1):
    for j in range(i + 1, r):
        if gcd(i, j) == 1:
            for k in range(j + 1, r + 1):
                if gcd(j, k) == 1 and gcd(k, i) == 1:
                    print(f'({i}, {j}, {k})')