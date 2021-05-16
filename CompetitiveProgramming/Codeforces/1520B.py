import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    ans = 0
    for i in range(9):
        cur = 1
        for j in range(i):
            cur = cur * 10 + 1
        start = cur
        for j in range(9):
            if start <= n:
                ans += 1
            start += cur
    print(ans)