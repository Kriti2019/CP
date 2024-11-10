class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0;

        for (auto el : nums) {
            if (el > nums[idx]) {
                idx++;
            }
        }

        return idx;
    }
};