import sys
sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = []
    for i in range(n):
        x, y = map(int,input().split())
        x, y = y, x
        a.append((x, y))
    a.sort()
    # print(a)
    ans = ""
    lastx = 0
    lasty = 0
    f = True
    for x, y in a:
        if x < lastx or y < lasty:
            f = False
            break
        distx = x - lastx
        disty = y - lasty
        ans += disty * "R"
        ans += distx * "U"
        lastx, lasty = x, y
    
    if not f:
        print('NO')
    else:
        print('YES')
        print(ans)