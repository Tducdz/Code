def Mayman(a):
    s = str(a)
    dem = 0
    for i in s:
        if (i == '4' or i == '7'):
            dem += 1
    if (dem == 4 or dem == 7):
        return True
    return False

n = int(input())
if (Mayman(n) == True):
    print("YES")
else:
    print("NO")