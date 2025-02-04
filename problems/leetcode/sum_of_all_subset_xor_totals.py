class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        sum = 0
        for mask in range(1<<len(nums)):
            xor = 0
            for j in range(len(nums)):
                if (mask >> j) & 1 == 1:
                    xor ^= nums[j]
            sum += xor
        return sum
