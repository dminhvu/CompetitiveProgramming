import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    cnt = {}
    dp = [0 for _ in range(n)]
    ans = 0
    for i in range(n):
        if a[i] not in cnt:
            cnt[a[i]] = 0   
        if i > 0:
            dp[i] = dp[i - 1] + cnt[a[i]]
        cnt[a[i]] += i + 1
        ans += dp[i]
    print(ans)