"""
References:
1. https://vnoi.info/wiki/algo/data-structures/segment-tree-extend.md
2. https://cp-algorithms.com/data_structures/segment_tree.html
"""


class SegmentTree:
    def __init__(self, nums):
        self.num_of_elements = len(nums)
        self.tree = [0 for _ in range(4 * self.num_of_elements)]
        self.nums = nums

        # call to build tree
        self.build_tree(0, 0, self.num_of_elements - 1)

    def build_tree(self, key, left, right):
        """
        This function intializes the tree with the given nums array.
        """
        # if left > right, this node does not exist
        if left > right:
            return
        # if left == right, this node has only 1 element
        if left == right:
            self.tree[key] = self.nums[left]
            return
        # divide into 2 parts, left tree and right tree with the boundary is mid
        mid = (left + right) // 2
        self.build_tree(key * 2 + 1, left, mid)
        self.build_tree(key * 2 + 2, mid + 1, right)
        # tree[key] will store the maximum element of its left and right branch
        # i.e. tree[key*2+1] and tree[key*2+2]
        self.tree[key] = max(self.tree[key * 2 + 1], self.tree[key * 2 + 2])

    def get_max(self, key, left, right, lower_bound, upper_bound):
        """
        This function gets max element in range [lower_bound - upper_bound].
        Notes: left < right, lower_bound < upper_bound
        """
        # if left > upper bound, this node does not exist
        # [[lower_bound - upper_bound] - [left - right]]
        # if right < lower_bound, this node does not exist
        # [[left - right] - [lower_bound - upper_bound]]
        # then return 0
        if left > upper_bound or right < lower_bound:
            return 0
        # if left >= lower_bound and right <= upper_bound
        # [left - right] is entirely in [lower_bound - upper_bound]
        # [lower_bound - [left - right] - upper_bound]
        # then return the whole tree of this node
        if left >= lower_bound and right <= upper_bound:
            return self.tree[key]
        # get max element from left tree and right tree
        mid = (left + right) // 2
        max_from_left_tree = self.get_max(
            key * 2 + 1, left, mid, lower_bound, upper_bound
        )
        max_from_right_tree = self.get_max(
            key * 2 + 2, mid + 1, right, lower_bound, upper_bound
        )
        return max(max_from_left_tree, max_from_right_tree)

    def query(self, lower_bound, upper_bound):
        """
        This function returns the answers for the queries by calling get_max().
        """
        answer = self.get_max(0, 0, self.num_of_elements, lower_bound, upper_bound)
        return answer


if __name__ == "__main__":
    num_of_elements, num_of_queries = map(int, input().split())
    nums = list(map(int, input().split()))

    segment_tree = SegmentTree(nums)

    for query in range(num_of_queries):
        lower_bound, upper_bound = map(int, input().split())
        answer = segment_tree.query(lower_bound, upper_bound)
        print(
            f"Query {query}: Max element in range [{lower_bound} - {upper_bound}] is {answer}"
        )
