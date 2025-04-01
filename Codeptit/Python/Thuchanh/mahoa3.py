def char_value(c):
    return ord(c) - ord('A')

def rotate_string(s, rotate_value):
    rotated = ""
    for ch in s:
        new_char = chr((char_value(ch) + rotate_value) % 26 + ord('A'))
        rotated += new_char
    return rotated

def merge_strings(s1, s2):
    merged = ""
    for i in range(len(s1)):
        new_char = chr((char_value(s1[i]) + char_value(s2[i])) % 26 + ord('A'))
        merged += new_char
    return merged

def drm_encode(s):
    n = len(s) // 2
    left = s[:n]
    right = s[n:]

    rotate_left_value = sum(char_value(ch) for ch in left)
    rotate_right_value = sum(char_value(ch) for ch in right)

    rotated_left = rotate_string(left, rotate_left_value)
    rotated_right = rotate_string(right, rotate_right_value)

    result = merge_strings(rotated_left, rotated_right)

    return result

T = int(input())
for _ in range(T):
    s = input().strip()
    print(drm_encode(s))