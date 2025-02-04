import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline
inf = int(1e9)

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    maxdiff = 0
    maxval = -inf
    for i in range(n):
        maxval = max(maxval, a[i])
        maxdiff = max(maxdiff, maxval - a[i])
    while maxdiff > 0:
        ans += 1
        maxdiff //= 2
    print(ans)
        