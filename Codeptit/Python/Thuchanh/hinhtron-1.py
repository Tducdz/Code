from itertools import combinations
import math

def is_inside_circle(x, y, cx, cy, r):
    # Kiểm tra điểm (x, y) có nằm trong đường tròn tâm (cx, cy) bán kính r
    dist_squared = (x - cx) ** 2 + (y - cy) ** 2
    return dist_squared < r ** 2

def circle_from_three_points(p1, p2, p3):
    # Tính tâm và bán kính đường tròn từ 3 điểm không thẳng hàng
    x1, y1 = p1
    x2, y2 = p2
    x3, y3 = p3

    # Tính determinant
    det = (x1 - x2) * (y2 - y3) - (x2 - x3) * (y1 - y2)
    if det == 0:
        return None, None  # 3 điểm thẳng hàng, không có đường tròn

    # Tâm (cx, cy)
    A = x1 ** 2 + y1 ** 2
    B = x2 ** 2 + y2 ** 2
    C = x3 ** 2 + y3 ** 2

    cx = ((A * (y2 - y3) + B * (y3 - y1) + C * (y1 - y2)) / (2 * det))
    cy = ((A * (x3 - x2) + B * (x1 - x3) + C * (x2 - x1)) / (2 * det))

    # Bán kính r
    r_squared = (x1 - cx) ** 2 + (y1 - cy) ** 2
    r = math.sqrt(r_squared)

    return (cx, cy, r)

def solve_test_case(N, K, points):
    for p1, p2, p3 in combinations(points, 3):
        # Tính tâm và bán kính đường tròn
        cx, cy, r = circle_from_three_points(p1, p2, p3)
        if cx is None:
            continue  # 3 điểm thẳng hàng, bỏ qua

        # Kiểm tra số điểm nằm trong đường tròn
        inside_count = 0
        for px, py in points:
            if (px, py) not in [p1, p2, p3] and is_inside_circle(px, py, cx, cy, r):
                inside_count += 1

        # Nếu số điểm nằm trong đường tròn đúng bằng K, trả về "YES"
        if inside_count == K:
            return "YES"

    # Không tìm được đường tròn thỏa mãn
    return "NO"

# Đọc input
T = int(input())
results = []
for _ in range(T):
    N = int(input())
    K = int(input())
    points = [tuple(map(int, input().split())) for _ in range(N)]
    results.append(solve_test_case(N, K, points))

# In kết quả
for i, res in enumerate(results, 1):
    print(f"Case #{i}: {res}")
