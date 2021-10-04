n = int(input())
for i in range(n):
    nxt = input()
    num = [int(d) for d in nxt]
    dig = [int(d) for d in str(sum(num))]
    if num == num[::-1] and dig == dig[::-1]:
        print("Y")
    else:
        print("N")