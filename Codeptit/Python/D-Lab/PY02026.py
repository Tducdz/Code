n, m = input().split()
n = int(n)
m = int(m)
a = sorted(list(set(input().split())), key = int)
b = sorted(list(set(input().split())), key = int)

if len(a) == len(b):
    dem = 0
    for i in range(0, len(a)):
        if a[i] != b[i]:
            dem += 1
            print("NO")
            break
    if dem == 0:
        print("YES")
else:
    print("NO")