n = input()
dem = 0
for i in range(0, len(n)):
    if n[i] == '4' or n[i] == '7':
        dem += 1
if dem == 4 or dem == 7:
    print("YES")
else:
    print("NO")