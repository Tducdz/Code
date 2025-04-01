import math
from itertools import combinations

def calculate_circle_center(p1, p2, p3):
    mid1 = ((p1[0] + p2[0]) / 2, (p1[1] + p2[1]) / 2)
    mid2 = ((p2[0] + p3[0]) / 2, (p2[1] + p3[1]) / 2)

    slope1 = (p2[0] - p1[0], p2[1] - p1[1])
    slope2 = (p3[0] - p2[0], p3[1] - p2[1])

    if slope1[0] != 0:
        slope1_perpendicular = (-slope1[1] / slope1[0], 1)
    else:
        slope1_perpendicular = (1, 0)

    if slope2[0] != 0:
        slope2_perpendicular = (-slope2[1] / slope2[0], 1)
    else:
        slope2_perpendicular = (1, 0)

    a1 = slope1_perpendicular[0]
    b1 = -1
    c1 = a1 * mid1[0] + mid1[1]

    a2 = slope2_perpendicular[0]
    b2 = -1
    c2 = a2 * mid2[0] + mid2[1]

    det = a1 * b2 - a2 * b1

    if det == 0:
        return None

    center_x = (b2 * c1 - b1 * c2) / det
    center_y = (a1 * c2 - a2 * c1) / det

    return (center_x, center_y)

def points_inside_circle(center, radius, points):
    count = 0
    for p in points:
        distance = math.sqrt((p[0] - center[0])**2 + (p[1] - center[1])**2)
        if distance < radius:
            count += 1
    return count

def solve_case(points, K):
    for p1, p2, p3 in combinations(points, 3):
        center = calculate_circle_center(p1, p2, p3)
        if center is None:
            continue

        radius = math.sqrt((p1[0] - center[0])**2 + (p1[1] - center[1])**2)

        inside_count = points_inside_circle(center, radius, points)

        if inside_count == K:
            return "YES"

    return "NO"

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        N = int(input())
        K = int(input())
        points = [tuple(map(int, input().split())) for _ in range(N)]
        print(solve_case(points, K))
