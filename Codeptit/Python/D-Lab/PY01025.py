n = input()
s = len(n)
k = 0
if (s % 3 == 0): k = 2
if (s % 3 == 2): k = 1
for i in range(s):
    print(n[i], end='')
    if i % 3 == k and i != s - 1:
        print(',', end='')