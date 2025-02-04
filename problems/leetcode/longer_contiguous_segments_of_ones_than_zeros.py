class Solution(object):
    def checkZeroOnes(self, s):
        """
        :type s: str
        :rtype: bool
        """
        max_zero = count_zero = 0
        max_one = count_one = 0
        for c in s:
            if c == '1':
                count_one += 1
                count_zero = 0
            else:
                count_zero += 1
                count_one = 0
            max_zero = max(max_zero, count_zero)
            max_one = max(max_one, count_one)
        return max_one > max_zero
