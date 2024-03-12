mod = 998244353
for _ in range(int(input())):
    n, x = map(int, input().split())
    prime_factors = []
    p = 2
    while p*p <= x:
        pw = 0
        while x%p == 0:
            x //= p
            pw += 1
        if pw > 0: prime_factors.append((p, pw))
        p += 1
    if x > 1: prime_factors.append((x, 1))
    ans = 0
    for l in range(1, n+1):
        ways = 1
        for p, pw in prime_factors:
            ways = ways * (pow(pw+1, l, mod) - pow(pw, l, mod)) % mod
        ans += ways
    print(ans % mod)