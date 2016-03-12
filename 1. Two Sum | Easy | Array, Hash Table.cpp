/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<pair<int, int> > arr;
        for (int i = 0; i < nums.size(); ++i) {
            arr.push_back(make_pair(nums[i], i));
        }
        sort(arr.begin(), arr.end());
        for (int i = 0, j = arr.size() - 1; i < j; ++i) {
            while (i < j && arr[i].first + arr[j].first > target) {
                --j;
            }
            if (i < j && arr[i].first + arr[j].first == target) {
                res.push_back(arr[i].second);
                res.push_back(arr[j].second);
                sort(res.begin(), res.end());
                break;
            }
        }
        return res;
    }
};
