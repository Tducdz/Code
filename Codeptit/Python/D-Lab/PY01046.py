def thapHN(n, A, B, C):
    if n == 0: 
        return
    thapHN(n - 1, A, C, B)
    print(A, '->', C)
    thapHN(n - 1, B, A, C)
    
n = int(input())
thapHN(n, 'A', 'B', 'C')
print()