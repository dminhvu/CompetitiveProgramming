import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

n = int(input())
a = [int(x) for x in str(n) ]

for i in range(len(a)):
    x = a[i]
    if x == 9:
        if i != 0:
            print(0,end='')
        else:
            print(9,end='')
    else:
        print(9 - x,end='') if 9 - x < x else print(x,end='')