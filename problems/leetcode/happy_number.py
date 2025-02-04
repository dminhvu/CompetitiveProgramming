class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        visited = {}
        visited[n] = 1
        while n != 1:
            cur_n = n
            n = 0
            while cur_n > 0:
                n += pow(cur_n % 10, 2)
                cur_n //= 10
            if n in visited:
                return False
            visited[n] = 1
        return True
