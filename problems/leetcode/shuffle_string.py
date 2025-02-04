class Solution(object):
    def restoreString(self, s, indices):
        """
        :type s: str
        :type indices: List[int]
        :rtype: str
        """
        ans = ["a" for _ in range(len(s))]
        for i, id in enumerate(indices):
            ans[id] = s[i]
        return "".join(ans)
