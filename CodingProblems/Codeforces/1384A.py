import sys
sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = []
    ans.append("a" * 51)
    for i in range(n):
        cur = [x for x in ans[i]]
        if cur[a[i]] == 'z':
            cur[a[i]] = 'a'
        else:
            cur[a[i]] = chr(ord(cur[a[i]]) + 1)
        ans.append("".join(cur))
    for x in ans:
        print(x)
    