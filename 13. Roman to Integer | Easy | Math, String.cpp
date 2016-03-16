/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
// I（1）、V（5）、X（10）、L（50）、C（100）、D（500）、 M（1000）
/* old version
class Solution {
public:
    int romanToInt(string s) {
        int nums[] = {1, 5, 10, 50, 100, 500, 1000}, res = 0;
        string chs("IVXLCDM??");
        for (int i = 0; i < s.size(); ++i) {
            int curi = chs.find(s[i]);
            if (curi & 1) {
                res += nums[curi];
                while (i + 1 < s.size() && curi > 0 && chs[curi - 1] == s[i + 1]) {
                    res += nums[curi - 1];
                    ++i;
                }
            } else {
                if (i + 1 < s.size() && chs[curi + 2] == s[i + 1]) {
                    res += nums[curi + 2] - nums[curi];
                    ++i;
                } else if (i + 1 < s.size() && chs[curi + 1] == s[i + 1]) {
                    res += nums[curi + 1] - nums[curi];
                    ++i;
                } else {
                    res += nums[curi];
                    while (i + 1 < s.size() && chs[curi] == s[i + 1]) {
                        res += nums[curi];
                        ++i;
                    }
                }
            }
        }
        return res;
    }
};
*/
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
            if (i + 1 < s.size() && dict[s[i]] < dict[s[i + 1]]) res -= dict[s[i]];
            else res += dict[s[i]];
        return res;
    }
};
