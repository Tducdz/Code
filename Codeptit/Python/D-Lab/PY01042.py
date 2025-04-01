for t in range(int(input())):
    s = input()
    check = True
    for i in s:
        if i != '0' and i != '1' and i != '2':
            print("NO")
            check = False
            break
    if check:
        print("YES")