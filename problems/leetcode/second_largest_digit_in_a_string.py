class Solution(object):
    def secondHighest(self, s):
        """
        :type s: str
        :rtype: int
        """
        digit_list = []
        for char in s:
            if char >= '0' and char <= '9':
                if char not in digit_list:
                    digit_list.append(char)
        digit_list.sort()
        if len(digit_list) >= 2:
            return digit_list[-2]
        else:
            return -1
