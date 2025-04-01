def solve():
    N, M, K = map(int, input().split())
    matrix = []
    for _ in range(N):
        row = input()
        matrix.append([int(x) for x in row])

    count = 0
    for r1 in range(N):
        for c1 in range(M):
            for r2 in range(r1, N):
                for c2 in range(c1, M):
                    current_sum = 0
                    for i in range(r1, r2 + 1):
                        for j in range(c1, c2 + 1):
                            current_sum += matrix[i][j]
                    if current_sum == K:
                        count += 1
    print(count)


T = int(input())
for _ in range(T):
    solve()