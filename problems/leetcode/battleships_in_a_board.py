class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        ans = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'X':
                    if i == 0 and j == 0:
                        ans += 1
                    elif i == 0 and j > 0 and board[i][j - 1] != 'X':
                        ans += 1
                    elif i > 0 and j == 0 and board[i - 1][j] != 'X':
                        ans += 1
                    elif board[i - 1][j] != 'X' and board[i][j - 1] != 'X':
                        ans += 1
        return ans
