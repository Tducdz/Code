def check(n):
    sum = 0
    for i in n:
        sum += int(i)
    if sum % 3 == 0:
        return 'YES'
    else:
        return 'NO'
for t in range(int(input())):
    print(check(input()))