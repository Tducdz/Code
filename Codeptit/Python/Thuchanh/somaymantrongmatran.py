n, m = map(int, input().split())

matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

max = max(max(row) for row in matrix)
min = min(min(row) for row in matrix)

lucky = max - min

positions = []
for i in range(n):
    for j in range(m):
        if matrix[i][j] == lucky:
            positions.append((i, j))

if positions:
    print(lucky)
    for point in positions:
        print("Vi tri [", point[0], "][", point[1], "]", sep="")
else:
    print("NOT FOUND")