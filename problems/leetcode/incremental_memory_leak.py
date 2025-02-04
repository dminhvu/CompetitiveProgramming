class Solution(object):
    def memLeak(self, memory1, memory2):
        """
        :type memory1: int
        :type memory2: int
        :rtype: List[int]
        """
        """
        Because i * (i + 1) <= 2 * (2^31 - 1)
        Thus, i <= 92682
        """
        i = 1
        while i <= 100000:
            if memory1 >= memory2:
                if memory1 >= i:
                    memory1 -= i
                else:
                    break
            else:
                if memory2 >= i:
                    memory2 -= i
                else:
                    break
            i += 1
        return [i, memory1, memory2]
