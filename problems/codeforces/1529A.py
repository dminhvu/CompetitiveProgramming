import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    ans = sum([a[i] != a[0] for i in range(n)])
    print(ans)