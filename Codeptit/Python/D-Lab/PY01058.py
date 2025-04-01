def snt(n):
    if n < 2:
        return False
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            return False
    return True

for t in range(int(input())):
    n = input()
    s = int(n[-4::])
    if snt(s):
        print("YES")
    else:
        print("NO")