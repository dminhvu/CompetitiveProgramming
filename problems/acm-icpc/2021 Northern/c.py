import fractions

n = int(input())

for _ in range(n):
    s = input()
    sum = 0
    for i in range(1,len(s)+1):
        if s[:i] == s[-i:]:
            sum += 2**i

    print(sum)
