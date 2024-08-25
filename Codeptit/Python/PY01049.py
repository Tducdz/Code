def nguyento(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

t = int(input())
for z in range(t):
    dem = 0
    s = input()
    if (nguyento(len(s))):
        for i in range(len(s)):
            if nguyento(int(s[i])) == True:
                dem += 1
        if (dem > (len(s) / 2)):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")