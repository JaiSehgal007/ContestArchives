def can_choose_elements(a, b, k):
    a = set(filter(lambda x: 1 <= x <= k, a))
    b = set(filter(lambda x: 1 <= x <= k, b))

    c = a - b
    d = b - a
    e = a | b  # Use | for set union

    if len(c) > k/2 or len(d) > k/2:
        return False

    if len(e) == k:
        return True

    return False


# Input
t=int(input())
while t:
    t-=1
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))


    # Check if it is possible to choose elements
    result = can_choose_elements(a, b, k)

    # Output
    if result:
        print("YES")
    else:
        print("NO")
