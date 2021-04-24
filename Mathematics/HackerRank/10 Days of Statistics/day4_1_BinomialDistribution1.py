# Enter your code here. Read input from STDIN. Print output to STDOUT
import math

def bindis(x,n,p):
    ncx = math.factorial(n) / (math.factorial(x) * math.factorial(n - x))
    return ncx * math.pow(p, x) * math.pow(1 - p, n - x)

boy_ratio, girl_ratio = map(float, input().split())
boy_rate = boy_ratio / (boy_ratio + girl_ratio)

ans = 0
for i in range(3,7):
    ans += bindis(i,6,boy_rate)
    
print('{0:.3f}'.format(ans))