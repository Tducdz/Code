def ucln(a, b):
    if b == 0: return a
    return ucln(b, a % b)
for t in range(int(input())):
    a = int(input())
    b = int(str(a)[::-1])
    if ucln(a, b) == 1:
        print("YES")
    else:
        print("NO")