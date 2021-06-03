def calc(n):
    dp = [0]
    sq = []
    for i in range(1,n+1):
        if i * i > n:
            break
        sq.append(i * i)
    for i in range(1,n+1):
        can_win = 0
        for j in sq:
            if j > i:
                break
            can_win |= dp[i - j] == 0
        dp.append(can_win)
    for i in range(len(dp)):
        print(i,end=' ')
    print()
    for i in dp:
        print(i,end=' ')
    print()
    return dp[-1] == 1

print(calc(20))