class Solution {
public:
    int64_t binpow(int a, int b, int mod) {
        if (b == 0) return 1;
        int64_t tmp = binpow(a, b/2, mod);
        tmp = (tmp % mod * tmp % mod) % mod;
        if (b&1) tmp = (tmp % mod * 1ll * a % mod) % mod;
        return tmp;
    }
    int64_t numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int right = n - 1;
        int64_t ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            while (i <= right && nums[i] + nums[right] > target) {
                right--;
            }
            if (i <= right) {
                ans += binpow(2, right - i, mod);
                ans %= mod;
            }
        }
        return ans;
    }
};
