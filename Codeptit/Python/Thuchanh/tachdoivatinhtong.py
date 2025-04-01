def tach_va_tinh_tong(N):
    while len(N) > 1:
        mid = len(N) // 2
        dau = N[:mid]
        cuoi = N[mid:]
        tong = str(int(dau) + int(cuoi))
        print(tong)
        N = tong

N = input().strip()
tach_va_tinh_tong(N)
