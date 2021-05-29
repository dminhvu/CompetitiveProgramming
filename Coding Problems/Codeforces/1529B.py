import sys
sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    ans = 0
    b = []
    for x in a:
        if x <= 0:
            b.append(x)
    b.sort()

    for x in range(n):
        if a[i] <= 0:
            continue
        if a[i] - b[-1] > 0:
            b.append(a[i])
            break
    print(len(b))


