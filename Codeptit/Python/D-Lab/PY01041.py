def check(n):
    if (n < 100):
        print("NO")
    else:
        s = str(n)
        diem = 0
        check1 = True
        while s[diem] < s[diem + 1]:
                diem += 1
        for i in range(diem, len(s) - 1):
            if (s[i] < s[i + 1]):
                check1 = False
        if check1:
            print("YES")
        else:
            print("NO")
        

for t in range(int(input())):
    n = int(input())
    check(n)