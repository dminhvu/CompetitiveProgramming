import sys
sys.stdin = open('input.txt','r')
input = sys.stdin.readline

def calc(a,n,m):
    ans = -1
    for i in range(n):
        if i != 0:
            a[i] += a[i - 1]
        a[i] %= m
        if a[i] != 0:
            ans = max(ans, i + 1)
    return ans

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    ans = -1
    ans = max(ans, calc(list(a),n,m))
    ans = max(ans, calc(list(a[::-1]),n,m))
    print(ans)

