import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    if n > 1099:
        print('YES')
        continue
    while n > 0:
        if n % 11 == 0:
            n %= 11
            break
        if n >= 111:
            n -= 111
        else:
            break
    if n == 0:
        print('YES')
    else:
        print('NO')