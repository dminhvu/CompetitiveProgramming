import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)
    
for _ in range(int(input())):
    n = int(input())
    print(int(100/gcd(n,100)))