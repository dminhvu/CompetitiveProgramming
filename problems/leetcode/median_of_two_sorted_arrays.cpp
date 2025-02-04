class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combine;
        int i = 0, j = 0;
        while (1) {
            if (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] < nums2[j]) {
                    combine.push_back(nums1[i++]);
                } else {
                    combine.push_back(nums2[j++]);
                }
            } else if (i < nums1.size()) {
                combine.push_back(nums1[i++]);
            } else if (j < nums2.size()) {
                combine.push_back(nums2[j++]);
            } else break;
        }
        if (combine.size() & 1) {
            return combine[combine.size() / 2];
        } else {
            return (double)(combine[combine.size() / 2 - 1] + combine[combine.size() / 2]) / 2;
        }
    }
};