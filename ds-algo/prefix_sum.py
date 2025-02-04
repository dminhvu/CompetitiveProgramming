"""
References:
1. https://vnoi.info/wiki/algo/data-structures/data-structures-overview.md#2-1-m%E1%BA%A3ng-c%E1%BB%99ng-d%E1%BB%93n-prefix-sum
"""


class PrefixSum:
    def __init__(self, nums):
        self.num_of_elements = len(nums)
        self.nums = nums
        self.prefix_sum = [0 for _ in range(self.num_of_elements)]
        self.build_prefix_sum_array()

    def build_prefix_sum_array(self):
        """
        This function initializes the prefix sum array.
        """
        self.prefix_sum[0] = self.nums[0]
        for i in range(1, self.num_of_elements):
            self.prefix_sum[i] = self.prefix_sum[i - 1] + self.nums[i]

    def get_sum(self, lower_bound, upper_bound):
        """
        This function calculates the sum of elements in range [lower_bound, upper_bound].
        """
        sum = self.prefix_sum[upper_bound]
        if lower_bound > 0:
            sum -= self.prefix_sum[lower_bound - 1]

        return sum

    def query(self, lower_bound, upper_bound):
        """
        This function returns the answers for queries.
        """
        answer = self.get_sum(lower_bound, upper_bound)
        return answer


if __name__ == "__main__":
    num_of_elements, num_of_queries = map(int, input().split())
    nums = list(map(int, input().split()))
    prefix_sum_array = PrefixSum(nums)

    for query in range(num_of_queries):
        lower_bound, upper_bound = map(int, input().split())
        answer = prefix_sum_array.query(lower_bound, upper_bound)
        print(
            f"Query {query}: Sum of elements in range [{lower_bound} - {upper_bound}] is {answer}"
        )
