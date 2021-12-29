import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

def greater(a, b):
    return a > b

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    ans = 0
    for i in range(n):
        if i % 2 == 0:
            if a[i] % 2 == 0:
                ans += a[i]
        else:
            if a[i] % 2 == 1:
                ans -= a[i]
    if ans == 0:
        print("Tie")
    elif ans > 0:
        print("Alice")
    else:
        print("Bob")

