# Enter your code here. Read input from STDIN. Print output to STDOUT
import math

numer, denom = map(int, input().split())
n = int(input())

rate = numer / denom

ans = math.pow(1 - rate, n - 1) * rate

print('{0:.3f}'.format(ans))
