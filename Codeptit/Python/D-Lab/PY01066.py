def check(s1):
    s2 = s1[::-1]
    for i in range(1, len(s1)):
        a = ord(s1[i]) - ord(s1[i - 1])
        b = ord(s2[i]) - ord(s2[i - 1])
        if abs(a) != abs(b):
            return False
    return True

for t in range(int(input())):
    s = input()
    if check(s):
        print("YES")
    else:
        print("NO")