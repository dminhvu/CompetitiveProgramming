import sys
sys.stdin = open('input.txt','r')
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    cnt = 0
    ans = 0
    for x in a:
        cnt += 1
        if cnt == x:
            ans += 1
            cnt = 0
    print(ans)