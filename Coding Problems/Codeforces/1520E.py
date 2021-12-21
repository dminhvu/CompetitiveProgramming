import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input()
    a = []
    ans = 0
    for i in range(n):
        if s[i] == '*':
            a.append(i)
    if len(a) == 0:
        print(0)
        continue
    pos = len(a) // 2
    cnt = 0
    for i in range(pos,-1,-1):
        ans += abs(a[pos] - cnt - a[i])
        cnt += 1
    cnt = 0
    for i in range(pos,len(a)):
        ans += abs(a[i] - a[pos] - cnt)
        cnt += 1
    print(ans)
