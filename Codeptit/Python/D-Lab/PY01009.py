s = input()
demThuong = 0
demHoa = 0
for i in range (len(s)):
    if(s[i].isupper()):
        demHoa += 1
    if(s[i].islower()):
        demThuong += 1
if(demHoa > demThuong):
    s = s.upper()
    print(s)
if(demHoa <= demThuong):
    s = s.lower()
    print(s)