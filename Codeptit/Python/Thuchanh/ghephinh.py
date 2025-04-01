from math import gcd

def lcm(a, b):
    return a * b // gcd(a, b)

def V(a, b, x):
    return x * (a - 2 * x) * (b - 2 * x)

def big(a, b):
    arr = []
    for i in range(1, min(a, b) // 2):
        arr.append(V(a, b, i))
    arr.sort(reverse=True)
    return arr[:3]

def find_min_books(a, b, x, y, z, l, r):
    volumes = big(a, b)
    V1, V2, V3 = volumes[0], volumes[1], volumes[2]

    k = -1
    for i in range(x, r + 1, V1):
        if i % V2 == y and i % V3 == z:
            k = i
            break
    
    if k == -1 or k < l:
        com = lcm(V1, lcm(V2, V3))
        d = (l - k) // com if k != -1 else (l // com)  # Tính toán d
        if d * com + k < l:
            d += 1
        return d * com + k if k != -1 else -1
    
    return k

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        a, b, x, y, z, l, r = map(int, input().split())
        result = find_min_books(a, b, x, y, z, l, r)
        print(result)
