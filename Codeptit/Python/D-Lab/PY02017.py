for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    m = {}
    for i in a:
        if m.get(i) is None:
            m[i] = 1
        else:
            m[i] += 1
    for i in m:
        if m[i] % 2 != 0:
            print(i)
            break