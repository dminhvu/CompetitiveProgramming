import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = []
    adj = [[] for i in range(n)]
    dp = [[0 for j in range(2)] for i in range(n)]
    def dfs(u,p):
        for v in adj[u]:
            if v == p:
                continue
            dfs(v,u)
            dp[u][0] += max(dp[v][1] + abs(a[u][0] - a[v][1]), dp[v][0] + abs(a[u][0] - a[v][0]))
            dp[u][1] += max(dp[v][0] + abs(a[u][1] - a[v][0]), dp[v][1] + abs(a[u][1] - a[v][1]))
    for i in range(n):
        l, r = map(int,input().split())
        a.append([l, r])
    for i in range(n-1):
        u, v = map(int,input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)
    dfs(0,-1)
    print(max(dp[0][0],dp[0][1]))