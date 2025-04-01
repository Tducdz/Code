# Hàm tính lũy thừa nhanh theo modulo
def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def solve():
    # Đọc N, M và xâu s
    N, M = map(int, input().split())
    s = input().strip()
    len_s = len(s)
    
    if N < len_s:
        print(0)
        return
    
    # Số lượng các cách chèn s vào t
    num_positions = N - len_s + 1
    
    # Tính số lượng các xâu t
    remaining_length = N - len_s
    power_of_26 = mod_exp(26, remaining_length, M)
    
    # Kết quả cuối cùng
    result = (num_positions * power_of_26) % M
    
    # Trừ đi trường hợp trùng lặp "aaa" (hoặc các xâu tương tự)
    if N == len_s:
        result = 1
    elif N > len_s:
        result = (result - mod_exp(26, N - len_s - 1, M) + M) % M
    
    print(result)

# Đọc số lượng test
T = int(input())
for _ in range(T):
    solve()
