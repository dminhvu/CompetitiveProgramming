class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = -1, -1
        min_val, max_val = nums[len(nums)-1], nums[0]
        for i in range(1,len(nums)):
            if nums[i] < max_val:
                right = i
            else:
                max_val = nums[i]
            if nums[len(nums)-1-i] > min_val:
                left = i
            else:
                min_val = nums[len(nums)-1-i]
        return max(0, right + left - len(nums) + 2)
