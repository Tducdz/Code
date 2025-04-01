def tong(n):
    s = 0
    for i in n:
        s += ord(i) - ord('0')
    return str(s)
if __name__ == "__main__":
    n = input()
    cnt = 0
    while len(n) > 1:
        cnt += 1
        n = tong(n)
    print(cnt)