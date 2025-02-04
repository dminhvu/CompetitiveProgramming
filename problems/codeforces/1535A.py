import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    a, b, c, d = map(int,input().split())
    if (max(a, b) == max(a, b, c) or max(a, b) == max(a, b, d)) \
        and (max(c, d) == max(a, c, d) or max(c, d) == max(b, c, d)):
            print("YES")
    else:
        print("NO")