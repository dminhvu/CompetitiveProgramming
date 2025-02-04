import sys
# sys.stdin = open('input.txt','r')
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input()
    f = False
    for i in range(n):
        for j in range(i+1,n):
            if s[i] == s[j]:
                for k in range(i+1,j):
                    f |= s[k] != s[i]
    print("YES") if f == False else print("NO")