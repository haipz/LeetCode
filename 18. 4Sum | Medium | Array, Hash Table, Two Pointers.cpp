/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> cp;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                cp.push_back(make_pair(nums[i] + nums[j], make_pair(i, j)));
            }
        sort(cp.begin(), cp.end());
        vector<vector<int>> res;
        for (int i = 0, j = cp.size() - 1; i < j; ++i) {
            if (cp[i].second.first && nums[cp[i].second.first] == nums[cp[i].second.first - 1]) continue;
            while (i < j && cp[i].first + cp[j].first > target) --j;
            if (i < j && cp[i].first + cp[j].first == target) {
                for (int k = j; k > i && cp[k].first == cp[j].first; --k) {
                    if (cp[k].second.first > cp[i].second.second) {
                        if (cp[k].second.first > cp[i].second.second + 1 && nums[cp[k].second.first] == nums[cp[k].second.first - 1]) continue;
                        res.push_back(vector<int>({nums[cp[i].second.first], nums[cp[i].second.second], nums[cp[k].second.first], nums[cp[k].second.second]}));
                    }
                }
            }
        }
        return res;
    }
};
