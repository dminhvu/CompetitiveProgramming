import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

nTest = int(input())

for _ in range(nTest):
    n = int(input())
    if n % 2050 != 0:
        print(-1)
        continue
    times = n / 2050
    ans = 0
    while times > 0:
        ans += times % 10
        times //= 10
    print(int(ans))