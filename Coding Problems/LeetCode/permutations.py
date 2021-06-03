class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        if n == 0:
            return [[]]
        res = []
        for i in range(n):
            for p in self.permute(nums[:i] + nums[i+1:]):
                res.append([nums[i]] + p)
        return res
        
