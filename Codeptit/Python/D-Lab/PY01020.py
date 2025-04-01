for t in range(int(input())):
    s = input()
    s = s[::-1]
    if len(s) >= 2 and s[0] == '6' and s[1] == '8':
        print("YES")
    else:
        print("NO")
