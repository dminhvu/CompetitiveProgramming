class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        ans = 0
        pref = [0 for _ in range(n)]
        for i in range(n):
            pref[i] = nums[i]
            if i > 0:
                pref[i] += pref[i - 1]
        for i in range(n):
            min_mid_id = -1
            max_mid_id = -1
            l = i + 1
            r = n - 1
            while l < r:
                mid = (l + r)//2
                sum_mid = pref[mid] - pref[i]
                sum_right = pref[n - 1] - pref[mid]
                if sum_mid >= pref[i] and sum_right >= sum_mid:
                    r = mid - 1
                else:
                    l = mid + 1
            min_mid_id = l
            l = i + 1
            r = n - 1
            while l < r:
                mid = (l + r)//2
                sum_mid = pref[mid] - pref[i]
                sum_right = pref[n - 1] - pref[mid]
                if sum_mid >= pref[i] and sum_right >= sum_mid:
                    l = mid + 1
                else:
                    r = mid - 1
            max_mid_id = l
            ans = (ans + max_mid_id - min_mid_id) % MOD
        return ans

if __name__ == '__main__':
	Solution s;
	print(s.waysToSplit([1,1,1]))