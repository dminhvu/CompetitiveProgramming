class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        for mask in range(1<<n):
            cur_list = []
            for j in range(n):
                if (mask >> j) & 1 == 1:
                    cur_list.append(nums[j])
            flag = (len(cur_list) >= 2)
            for i in range(len(cur_list)-1):
                if cur_list[i] > cur_list[i + 1]:
                    flag = False
                    break
            if flag:
                if cur_list not in ans:
                    ans.append(cur_list)
        return ans
        
