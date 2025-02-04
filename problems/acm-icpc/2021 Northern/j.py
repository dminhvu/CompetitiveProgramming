n, m = map(int, input().split())
a, b = [], []
for _ in range(n):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)

l = 0
r = int(1e16)
ans = 0

while l <= r:
    mid = (l + r) // 2
    sum = 0
    for i in range(n):
        q = mid - mid // (b[i] + 1)
        sum += q * a[i]
    if int(sum) >= m:
        r = mid - 1
        ans = mid
    else:
        l = mid + 1

print(ans)

