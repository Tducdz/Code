def tong(n):
    sum = 0
    for i in range(0, len(n)):
        if i % 2 == 0:
            sum += int(n[i])
    return sum

def tich(n):
    mul = 1
    dem = 0
    for i in range(0, len(n)):
        if i % 2 != 0 and int(n[i]) != 0:
            mul *= int(n[i])
            dem += 1
    if dem == 0:
        return 0
    else:
        return mul

for t in range(int(input())):
    n = input()
    print(f'{tong(n)} {tich(n)}')