class Solution(object):
    def makeGood(self, s):
        """
        :type s: str
        :rtype: str
        """
        while True:
            f = False
            for i in range(1,len(s)):
                if s[i - 1].islower() and upper(s[i - 1]) == s[i]:
                    f = True
                    s = s[:i - 1] + s[i + 1:]
                    break
                if s[i].islower() and upper(s[i]) == s[i - 1]:
                    f = True
                    s = s[:i - 1] + s[i + 1:]
                    break
            if not f:
                break
        return s
        
