import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n, l, r = map(int,input().split())
    left = [0 for __ in range(n)]
    right = [0 for __ in range(n)]
    a = list(map(int,input().split()))
    for i in range(l):
        left[a[i] - 1] += 1
    for i in range(l,n):
        right[a[i] - 1] += 1
    for i in range(n):
        min_cnt = min(left[i],right[i])
        left[i] -= min_cnt
        right[i] -= min_cnt
        l -= min_cnt
        r -= min_cnt
    ans = 0
    if l < r:
        l, r = r, l
        left, right = right, left
    for i in range(n):
        extra = l - r
        can_do = left[i]//2
        do = min(can_do*2,extra)
        ans += do//2
        l -= do
    ans += (l - r)//2 + (l + r)//2
    print(ans)