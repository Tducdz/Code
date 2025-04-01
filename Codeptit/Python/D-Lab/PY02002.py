a = []
for i in range(1, 94):
    a.append(0)
a[1] = 1
a[2] = 1
for i in range(3, 93):
    a[i] = a[i - 1] + a[i - 2]

for t in range(int(input())):
    m, n = map(int, input().split())
    for i in range(m, n + 1):
        print(a[i], end=' ')
    print()