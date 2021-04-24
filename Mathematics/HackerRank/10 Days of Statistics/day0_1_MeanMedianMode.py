# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(input())
a = list(map(int, input().split()))

# calculating mean
sum = 0
for val in a:
    sum += val
mean = sum / n
print(mean)

# calculating median
median = 0
if n % 2 == 1:
    median = sorted(a)[n // 2]
else:
    median = (sorted(a)[n // 2 - 1] + sorted(a)[n // 2] ) / 2
print(median)


# calculating mode
cnt = [0 for _ in range(100001)]
maxcnt = 0
mode = 100001

for val in a:
    cnt[val] += 1
for i in range(100001):
    if cnt[i] > maxcnt:
        maxcnt = cnt[i]
        mode = i
print(mode)