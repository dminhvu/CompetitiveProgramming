class Solution(object):
    def findNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for val in nums:
            cur = val
            cnt = 0
            while cur > 0:
                r = cur % 10
                cnt += 1
                cur //= 10
            ans += cnt % 2 == 0
        return ans
