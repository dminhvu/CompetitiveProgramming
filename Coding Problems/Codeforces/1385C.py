import sys
sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    i = n - 1
    while i >= 0:
        if i > 0 and a[i - 1] >= a[i]:
            i -= 1
        elif i == 0:
            i -= 1
        else:
            break
    while i >= 0:
        if i > 0 and a[i - 1] <= a[i]:
            i -= 1
        elif i == 0:
            i -= 1
        else:
            break
    print(max(0, i))