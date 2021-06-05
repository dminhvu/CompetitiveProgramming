class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        import collections
        dic = collections.OrderedDict()
        if k == 0:
            return False
        for val in nums:
            key = val // (t + 1)
            for m in [dic.get(key-1),dic.get(key),dic.get(key+1)]:
                if m != None and abs(val - m) <= t:
                    return True
            if len(dic) == k:
                dic.popitem(last=False)
            dic[key] = val
        return False
