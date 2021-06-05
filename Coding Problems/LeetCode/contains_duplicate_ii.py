class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dic = {}
        for i in range(len(nums)):
            j = dic.get(nums[i]);
            if j != None and i - j <= k:
                return True
            dic[nums[i]] = i
        return False
