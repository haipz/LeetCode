/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = nums.size() - 1; j < k; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                while (k > j && nums[i] + nums[j] + nums[k] > 0) --k;
                if (j < k && nums[i] + nums[j] + nums[k] == 0) res.push_back(vector<int>({nums[i], nums[j], nums[k]}));
            }
        }
        return res;
    }
};
