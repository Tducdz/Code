t = int(input())
while (t > 0):
    n = int(input())
    s = str(n)
    dau = s[0] + s[1]
    cuoi = s[len(s) - 2] + s[len(s) - 1]
    if (dau == cuoi):
        print("YES")
    else:
        print("NO")
    t -= 1