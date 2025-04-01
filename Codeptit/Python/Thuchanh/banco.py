from collections import deque

def is_valid_move(state, u, v, x, y):
    return 0 <= x < 4 and 0 <= y < 4 and state[x][y] == 0

def get_neighbors(state):
    moves = []
    for i in range(4):
        for j in range(4):
            if state[i][j] == 1:  # Nếu có quân cờ tại (i, j)
                for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:  # Các bước di chuyển
                    x, y = i + di, j + dj
                    if is_valid_move(state, i, j, x, y):
                        new_state = [row[:] for row in state]
                        new_state[i][j] = 0
                        new_state[x][y] = 1
                        moves.append((new_state, (i, j, x, y)))  # Trả về trạng thái mới và bước di chuyển
    return moves

def bfs(start, goal):
    queue = deque([(start, [])])
    visited = set()
    visited.add(tuple(map(tuple, start)))

    while queue:
        current_state, path = queue.popleft()

        if current_state == goal:
            return path

        for next_state, move in get_neighbors(current_state):
            state_tuple = tuple(map(tuple, next_state))
            if state_tuple not in visited:
                visited.add(state_tuple)
                queue.append((next_state, path + [move]))

def print_result(moves):
    print(len(moves))
    for move in moves:
        # Chuyển từ chỉ số 0 thành chỉ số 1
        print(move[0] + 1, move[1] + 1, move[2] + 1, move[3] + 1)  

# Nhập dữ liệu
start = [list(map(int, input().split())) for _ in range(4)]
goal = [list(map(int, input().split())) for _ in range(4)]

# Thực hiện BFS
result_moves = bfs(start, goal)

# In kết quả
print_result(result_moves)
