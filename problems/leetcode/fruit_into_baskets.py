class Solution(object):
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        max_amount = 0
        j = 0
        number_of_different_types = 0
        number_of_types = [0 for _ in range(len(tree))]
        for i in range(len(tree)):
            number_of_types[tree[i]] += 1
            if number_of_types[tree[i]] == 1:
                number_of_different_types += 1
            while number_of_different_types > 2:
                number_of_types[tree[j]] -= 1
                if number_of_types[tree[j]] == 0:
                    number_of_different_types -= 1
                j += 1
            max_amount = max(max_amount,i-j+1)

        return max_amount
