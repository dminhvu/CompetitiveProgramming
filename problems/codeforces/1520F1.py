import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

n, t = map(int,input().split())

for _ in range(t):
    k = int(input())
    cnt_zero = 0
    l = 1
    r = n
    while l < r:
        mid = (r + l - 1) // 2
        print("? {} {}".format(l,mid))
        sys.stdout.flush()
        total_one_left = int(input())
        total_zero_left = mid - l + 1 - total_one_left
        if cnt_zero + total_zero_left >= k:
            r = mid
        else:
            l = mid + 1
            cnt_zero += total_zero_left
    print("! {}".format(l))
        