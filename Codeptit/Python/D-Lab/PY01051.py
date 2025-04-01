def check(n):
    sum = 0
    for i in n:
        sum += int(i)
    sumstr = str(sum)
    if len(sumstr) <= 1:
        print("NO")
        return
    dao = sumstr[::-1]
    if sum == int(dao):
        print("YES")
    else:
        print("NO")
        
for t in range(int(input())):
    n = input()
    check(n)