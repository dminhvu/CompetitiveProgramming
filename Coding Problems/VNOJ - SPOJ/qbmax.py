import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

n, m = map(int,input().split())
a = [[] for _ in range(n)]
for i in range(n):
    a[i] = list(map(int,input().split()))


dp = [[-10**9 for j in range(m)] for i in range(n)]
for i in range(n):
    dp[i][0] = a[i][0]

for j in range(1,m):
    for i in range(n):
        dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j])
        if i > 0:
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j])
        if i < n - 1:
            dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + a[i][j])

ans = -10**9

for i in range(n):
    ans = max(ans, dp[i][m - 1])

print(ans)
