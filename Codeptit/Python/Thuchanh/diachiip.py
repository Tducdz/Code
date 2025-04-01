t = int(input())
for i in range (1, t + 1):
    s = 0
    str = input()
    xet = str.split(".")
    if len(xet) != 4:
        print("NO")
    else:
        for a in xet:
            if (a < '0' or a > '255'):
                s += 1
                break
        if s == 0:
            print("YES")
        else:
            print("NO")