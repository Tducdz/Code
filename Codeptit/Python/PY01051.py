def thuannghich(n):
    if len(str(n)) % 2 == 1:
        for z in range((len(str(n)) - 1) / 2):
            if (n[z] != n[len(str(n)) - 1]):
                return False
        return True
    else:
        for z in range(len(str(n)) / 2):
            if (n[z] != n[len(str(n)) - 1]):
                return False
        return True


t = int(input())
for i in range(t):
    s = input()
    tongcs = 0
    for z in s:
        tongcs += int(z)
    if thuannghich(tongcs):
        print("YES")
    else: 
        print("NO")