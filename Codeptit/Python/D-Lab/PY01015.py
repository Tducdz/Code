for t in range(int(input())):
    n = input()
    check = True
    for i in range(0, len(n) - 1):
        if n[i] > n[i + 1]:
            print("NO")
            check = False
            break
    if check == True:
        print("YES")