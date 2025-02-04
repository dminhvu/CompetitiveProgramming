class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        ans = 0
        for x in nums:
            ans += (x != val)
        while len(nums) > 0 and val in nums:
            nums.remove(val)
        return ans
