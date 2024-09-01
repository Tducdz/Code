a = []
while len(a) < 10:
    inputs = input().split()
    a.extend(map(int, inputs))
b = [0 for i in range(42)]
for i in a:
    b[i % 42] = 1
print(sum(b))