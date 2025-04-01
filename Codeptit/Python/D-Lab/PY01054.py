def tichcs(n):
    tich = 1
    for i in n:
        if int(i) != 0:
            tich *= int(i)
    return tich
for t in range(int(input())):
    n = input()
    print(tichcs(n))