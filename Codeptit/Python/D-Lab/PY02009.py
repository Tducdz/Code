n = int(input())
for i in range(n):
    m = int(input())
    a = []
    for k in range(m):
        a.append(int(input()))
    b = [0] * 1001
    max,ans =0,0
    for j in a:
        b[j] += 1
        if b[j] > max or (b[j] >= max and j < ans):
            max = b[j]
            ans = j
    print(ans)