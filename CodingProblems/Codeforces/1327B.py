import sys
sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    f = [False for i in range(n)]
    b = []
    id = []
    for i in range(n):
        a = list(map(int, input().split()))
        k = a[0]
        a.remove(a[0])
        opt = False
        for j in range(k):
            a[j] -= 1
        for j in a:
            if not f[j]:
                f[j] = True
                opt = True
                break
        if not opt:
            b.append(a)
            id.append(i)
    if len(b) > 0:
        found = False
        num = n - 1
        while num >= 0 and f[num]:
            num -= 1
        if num == -1:
            print("OPTIMAL")
            continue
        for i in range(len(b)):
            if num not in b[i]:
                found = True
                print("IMPROVE")
                print("{} {}".format(id[i] + 1, num + 1))
                break
        if not found:
            print("OPTIMAL")
    else:
        print("OPTIMAL")
        