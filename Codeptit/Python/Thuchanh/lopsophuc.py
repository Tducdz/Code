for t in range(int(input())):
    a = list(map(int, input().split()))
    x = complex(a[0],a[1])
    y = complex(a[2], a[3])
    c = (x+y)*x
    d = (x+y)*(x+y)
    a = list(map(int, [c.real, c.imag, d.real, d.imag]))
    print(f'{a[0]} + {a[1]}i, {a[2]} + {a[3]}i')