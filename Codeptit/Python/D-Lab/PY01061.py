def snt(n):
    if n < 2:
        return False
    for i in range(2, n //2 + 1):
        if n % i == 0:
            return False
    return True

def check(n):
    s1 = int(n[0:3:])
    s2 = int(n[-3::])
    if snt(s1) and snt(s2):
        return True
    return False

for t in range(int(input())):
    n = input()
    if check(n):
        print("YES")
    else:
        print("NO")