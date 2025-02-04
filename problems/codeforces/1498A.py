import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

def sum_of_digits(n):
    ans = 0
    while n > 0:
        ans += n % 10
        n //= 10
    return ans

def gcd(a, b):
    while b > 0:
        a %= b
        a, b = b, a
    return a

def calc(n):
    return gcd(n, sum_of_digits(n))

for _ in range(int(input())):
    n = int(input())
    while calc(n) == 1:
        n += 1
    print(n)