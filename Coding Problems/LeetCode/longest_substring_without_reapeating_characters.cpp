class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(129, 0);
        int j = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            cnt[(int)s[i]] += 1;
            while (cnt[(int)s[i]] > 1) {
                cnt[(int)s[j++]] -= 1;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};