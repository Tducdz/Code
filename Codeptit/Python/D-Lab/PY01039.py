def check(n):
    s = str(n)
    mang = list(set(s))
    if len(mang) == 2:
        m = len(s)
        check2 = True
        for i in range(m - 1):
            if (s[i] == s[i + 1]):
                check2 = False
        if check2:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")

for t in range(int(input())):
    n = int(input())
    check(n)