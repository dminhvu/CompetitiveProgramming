import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input()
    cnt = 0
    for i in range(n):
        cnt += s[i] == '0'
    if cnt == 1:
        print("BOB")
    elif cnt & 1 == 0:
        print("BOB")
    else:
        print("ALICE")