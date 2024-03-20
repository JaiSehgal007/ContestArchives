for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = 0
    same = 0
    for i in range(n-2):
        st = {s[i], s[i+1], s[i+2]}
        if len(st) == 1: same = 1
        elif len(st) == 3: ans += 1
        else:
            if i == 0 or s[i] != s[i+2] or s[i] != s[i-1]: ans += 1
    print(ans+same)