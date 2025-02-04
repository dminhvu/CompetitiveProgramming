import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

n = int(input())
t = list(map(int,input().split()))
r = list(map(int,input().split()))

dp = [10**9 for _ in range(n)]

dp[0] = t[0]
dp[1] = min(t[0] + t[1], r[0])

for i in range(2,n):
    dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1])

print(dp[n - 1])