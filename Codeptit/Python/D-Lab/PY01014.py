a, k, n = input().split()
a = int(a)
k = int(k)
n = int(n)

t = a % k
sodau = k - t
if a + sodau > n:
    print(-1)
else:
    print(sodau, end=' ')
    while sodau + k <= (n - a):
        sodau += k
        print(sodau, end=' ')