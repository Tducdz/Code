s = input()
if (s[2] != '+' or s[6] != '='):
    print("NO")
else: 
    if (int(s[0]) + int(s[4]) == int(s[8])):
        print("YES")
    else:
        print("NO")