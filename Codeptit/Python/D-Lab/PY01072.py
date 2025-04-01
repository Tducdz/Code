from itertools import combinations

n, k = map(int, input().split())
a = set(input().split())
b = sorted(a, key=int)
c = combinations(b, k)
ans = [' '.join(x) for x in c]
print('\n'.join(ans))