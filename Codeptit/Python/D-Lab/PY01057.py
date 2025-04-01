def snt(n):
    if n < 2:
        return False
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            return False
    return True

for t in range(int(input())):
    n = input()
    dem = 0
    for i in range(0, len(n) - 1):
        if snt(i):
            if snt((int)(n[i])) == False:
                print("NO")
                dem += 1
                break
        else:
            if snt((int)(n[i])):
                print("NO")
                dem += 1
                break
    if dem == 0:
        print("YES")