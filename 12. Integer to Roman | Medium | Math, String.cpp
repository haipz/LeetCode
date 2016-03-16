/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
// I（1）、V（5）、X（10）、L（50）、C（100）、D（500）、 M（1000）
class Solution {
public:
    string intToRoman(int num) {
        int nums[] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000};
        string chs("IVXLCDM??"), roman;
        for (int i = chs.size() - 2; i >= 0; i -= 2) {
            if (num >= nums[i - 1]*9) {
                num -= nums[i - 1]*9;
                roman += chs[i - 1];
                roman += chs[i + 1];
            } else if (num >= nums[i]) {
                num -= nums[i];
                roman += chs[i];
                while (num >= nums[i - 1]) {
                    num -= nums[i - 1];
                    roman += chs[i - 1];
                }
            } else if (num >= nums[i] - nums[i - 1]) {
                num -= nums[i] - nums[i - 1];
                roman += chs[i - 1];
                roman += chs[i];
            } else {
                while (num >= nums[i - 1]) {
                    num -= nums[i - 1];
                    roman += chs[i - 1];
                }
            }
        }
        return roman;
    }
};
