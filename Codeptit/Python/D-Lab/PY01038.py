for t in range(int(input())):
    n = int(input())
    dem = 0
    check = False
    while check == False:
        if (n % 7 == 0 or dem > 1000):
            check = True
        else:
            n += int(str(n)[::-1])
            dem += 1
    if n % 7 == 0:
        print(n)
    else:
        print(-1)    