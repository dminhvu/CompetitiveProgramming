class Solution:
    def minPartitions(self, n: str) -> int:
        return int(sorted([digit for digit in n])[-1])
            
