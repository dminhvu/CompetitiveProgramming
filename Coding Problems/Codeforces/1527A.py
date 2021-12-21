import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())): 
    n = int(input())
    k = 0
    while pow(2, k + 1) - 1 < n:
        k += 1
    print(pow(2, k) - 1)