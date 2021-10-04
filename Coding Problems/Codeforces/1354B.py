import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

inf = int(1e9)

for _ in range(int(input())):
    s = input()
    cnt1, cnt2, cnt3 = 0, 0, 0
    l = 0
    ans = inf
    cnt = [0 for i in range(3)]
    for r in range(len(s)):
        cnt[0] += (s[r] == '1')
        cnt[1] += (s[r] == '2')
        cnt[2] += (s[r] == '3')
        while l <= r and cnt[int(s[l]) - 1] > 1:
            cnt[int(s[l]) - 1] -= 1
            l += 1
        if cnt[0] > 0 and cnt[1] > 0 and cnt[2] > 0:
            ans = min(ans, r - l + 1)
    ans = 0 if ans == inf else ans
    print(ans)
