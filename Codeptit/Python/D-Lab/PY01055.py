def check(n):
    if len(n) % 2 == 0:
        return "NO"
    if n[0] == n[1]:
        return "NO"
    if len(n) >= 3:
        for i in range(2, len(n) - 1, 2):
            if n[i] != n[0]:
                return "NO"
    return "YES"

for t in range(int(input())):
    n = input()
    print(check(n))