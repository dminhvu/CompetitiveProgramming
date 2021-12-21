# Enter your code here. Read input from STDIN. Print output to STDOUT
import math

numer, denom = map(int, input().split())

n = int(input())

rate = numer / denom

ans = 0

for i in range(0,n):
    ans += math.pow(1 - rate, i) * rate
    
print('{0:.3f}'.format(ans))