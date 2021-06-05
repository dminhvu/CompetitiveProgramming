import sys
sys.stdin = open('input.txt','r')
input = sys.stdin.readline

def gcd(a,b):
    while b > 0:
        a %= b
        a, b = b, a
    return a

for _ in range(int(input())):
    n = int(input())
    a = sorted(list(map(int,input().split())),reverse=True)
    ans = 0
    for i in range(n):
        for j in range(i+1,n):
            ans += gcd(a[i],a[j]*2) > 1
    print(a)
    print(ans)