def check1(n):
    sum = 0
    for i in range(len(n)):
        sum += int(n[i])
    if sum % 10 == 0:
        return True
    else:
        return False
    
def check2(n):
    for i in range(0, len(n) - 1):
        if abs(int(n[i]) - int(n[i + 1])) != 2:
            return False
    return True

for i in range(int(input())):
    n = input()
    if (check1(n) and check2(n)):
        print("YES")
    else:
        print("NO")