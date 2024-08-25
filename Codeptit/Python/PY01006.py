def Mayman(a):
    s = str(a)
    for i in s:
        if (i != '4' and i != '7'):
            return False
    return True

i = int(input())
for z in range(i):
    n = int(input())
    if (Mayman(n) == True):
        print("YES")
    else:
        print("NO")