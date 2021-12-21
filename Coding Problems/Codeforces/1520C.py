import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    if n == 2:
        print(-1)
        continue
    cur = 1
    for i in range(n*n):
        if cur > n * n:
            cur = 2
        print(cur,end=' ')
        cur += 2
        if (i + 1) % n == 0:
            print("")