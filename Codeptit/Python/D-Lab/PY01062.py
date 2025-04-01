def snt(n):
    if n < 2:
        return False
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            return False
    return True

def check(n):
    if snt(len(n)) == False:
        return False
    else:
        nguyento = 0
        khongnguyento = 0
        for i in n:
            if snt(int(i)):
                nguyento += 1
            else:
                khongnguyento += 1
        if nguyento > khongnguyento:
            return True
        else:
            return False
        
for t in range(int(input())):
    n = input()
    if (check(n)):
        print("YES")
    else:
        print("NO")