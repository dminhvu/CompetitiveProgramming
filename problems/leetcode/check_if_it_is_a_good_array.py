class Solution(object):
    def isGoodArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def gcd(a,b):
            while b > 0:
                a %= b
                a, b = b, a
            return a
        ans = nums[0]
        for i in range(1,len(nums)):
            ans = gcd(ans,nums[i])
        return ans == 1
