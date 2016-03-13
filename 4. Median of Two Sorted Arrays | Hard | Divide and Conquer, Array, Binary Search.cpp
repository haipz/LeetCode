/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
    double findKth(vector<int>::iterator nums1, int m, vector<int>::iterator nums2, int n, int k) {
        if (m > n) {
            return findKth(nums2, n, nums1, m, k);
        }
        if (m == 0) {
            return nums2[k - 1];
        }
        if (k == 1) {
            return min(nums1[0], nums2[0]);
        }
        int l1 = min(k/2, m), l2 = k - l1;
        if (nums1[l1 - 1] >= nums2[l2 - 1]) {
            return findKth(nums1, m, nums2 + l2, n - l2, k - l2);
        } else {
            return findKth(nums1 + l1, m - l1, nums2, n, k - l1);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), (nums1.size() + nums2.size())/2 + 1);
        } else {
            double num1 = findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), (nums1.size() + nums2.size())/2);
            double num2 = findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), (nums1.size() + nums2.size())/2 + 1);
            return (num1 + num2)/2.0;
        }
    }
};
