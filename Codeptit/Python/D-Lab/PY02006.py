for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    s = 0
    for i in range(n):
        if (a[i] > b[i]):
            break
        else:
            s += 1
    if (s == n):
        print("YES")
    else:
        print("NO")