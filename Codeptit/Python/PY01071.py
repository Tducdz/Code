s = input()
n = len(s) - 3
if (s[n] == '.') and ((s[n + 1] =='p') or (s[n + 1] == 'P')) and ((s[n + 2] == 'y') or (s[n + 2] == 'Y')):
    print("yes")
else:
    print("no")