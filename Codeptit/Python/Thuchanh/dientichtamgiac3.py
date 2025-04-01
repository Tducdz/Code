from shapely.geometry import Polygon
from shapely.ops import unary_union

def main():
    N = int(input())
    triangles = []
    
    for _ in range(N):
        x1, y1, x2, y2, x3, y3 = map(int, input().split())
        triangle = Polygon([(x1, y1), (x2, y2), (x3, y3)])
        triangles.append(triangle)

    # Tính diện tích tổng hợp của các tam giác
    union_area = unary_union(triangles).area

    # In ra kết quả với độ chính xác 6 chữ số
    print(f"{union_area:.6f}")

if __name__ == "__main__":
    main()
