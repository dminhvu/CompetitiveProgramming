import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    cnt = {}
    ans = 0
    for i in range(n):
        if a[i] - i - 1 not in cnt:
            cnt[a[i] - i - 1] = 0
        ans += cnt[a[i] - i - 1]
        cnt[a[i] - i - 1] += 1
    print(ans)