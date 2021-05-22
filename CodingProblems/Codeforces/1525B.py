import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    if sorted(a) == a:
        print(0)
    elif a[0] == 1 or a[n - 1] == n:
        print(1)
    elif a[0] == n and a[n - 1] == 1:
        print(3)
    else:
        print(2)