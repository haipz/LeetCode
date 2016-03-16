/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, mi = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1, k = nums.size() - 1; j < k; ++j) {
                while (k > j && nums[i] + nums[j] + nums[k] > target) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < mi) {
                        mi = abs(sum - target);
                        res = sum;
                    }
                    --k;
                }
                if (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < mi) {
                        mi = abs(sum - target);
                        res = sum;
                    }
                }
            }
        return res;
    }
};
