class Solution(object):
    def winnerSquareGame(self, n):
        """
        :type n: int
        :rtype: bool
        """
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
        return dp[-1] == 1
