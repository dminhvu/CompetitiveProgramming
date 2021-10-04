# Enter your code here. Read input from STDIN. Print output to STDOUT
import math

lmd = float(input())
k = int(input())

ans = (math.pow(lmd, k) * math.pow(math.e, -lmd)) / math.factorial(k)

print('{0:.3f}'.format(ans))