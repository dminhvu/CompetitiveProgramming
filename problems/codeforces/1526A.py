import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    n *= 2
    a = list(map(int,input().split()))
    a.sort()
    b = []
    i = 0
    j = n - 1
    cur = 0
    while i <= j:
        if not cur:
            b.append(a[i])
            i += 1
        else:
            b.append(a[j])
            j -= 1
        cur ^= 1
    for x in b:
        print(x,end=' ')
    print()