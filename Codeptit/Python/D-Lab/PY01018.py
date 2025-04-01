P = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."
while True:
    d = input().split()
    k = int(d[0])
    if (k == 0):
        break
    s = ""
    n = d[1]
    for i in range(0, len(n)):
        tmp = P.find(str(n[i]))
        s += P[(tmp + k) % 28]
    print(s[::-1])