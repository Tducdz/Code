for t in range(int(input())):
    s = input()
    n = input()
    cnt = 0
    dem = 0
    if s.find(n, cnt) == -1:
        print(0)
    else:
        while s.find(n, cnt) != -1:
            x = s.find(n, cnt)   
            cnt = x + len(n)
            dem += 1
        print(dem)