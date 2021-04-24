# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
def bindis(x,n,p):
    ncx = math.factorial(n) / (math.factorial(x) * math.factorial(n - x))
    return ncx * math.pow(p, x) * math.pow(1 - p, n - x)

p, n = map(int, input().split())

p = p / 100

ans_1 = 0
ans_2 = 0
for i in range(0,3):
    ans_1 += bindis(i,n,p)
    
for i in range(2,n+1):
    ans_2 += bindis(i,n,p)
    
print('{0:.3f}'.format(ans_1))
print('{0:.3f}'.format(ans_2))