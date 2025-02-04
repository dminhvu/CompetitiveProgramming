import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    ans = 0
    a.sort()
    ans = sum([x <= 0 for x in a])
    mn = min([x if x > 0 else 10**9 + 7 for x in a])
    flag = (mn < 10**9 + 7)
    for i in range(1,n):
        if a[i] <= 0:
            flag &= (a[i] - a[i - 1] >= mn)
    if flag == True:
        print(ans + 1)
    else:
        print(ans)