class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dic = {}
        for val in nums:
            if dic.get(val) == None:
                dic[val] = 1
            else:
                dic[val] += 1

        for key in dic:
            if dic[key] >= 2:
                return True
        return False
