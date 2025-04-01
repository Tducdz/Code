def snt(n):
    if n < 2:
        return False
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            return False
    return True

def check1(n):
    sum = 0
    for i in n:
        sum += int(i)
    if snt(sum):
        return True

def check2(n):
    for i in range(0, len(n) - 1):
        if i % 2 == 0:
            if (int)(n[i]) % 2 != 0:
                return False
        else:
            if (int)(n[i]) % 2 == 0:
                return False
    return True

for t in range(int(input())):
    n = input()
    if check1(n) and check2(n):
        print("YES")
    else:
        print("NO")