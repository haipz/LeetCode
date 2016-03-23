/*
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const char btn[][5] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res[2];
        int pnt = 0;
        if (digits.empty()) return res[pnt];
        res[pnt].push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            res[pnt^1].clear();
            int num = digits[i] - '0';
            for (int j = 0; j < res[pnt].size(); ++j)
                for (int k = 0; k < strlen(btn[num]); ++k)
                    res[pnt^1].push_back(res[pnt][j] + btn[num][k]);
            pnt ^= 1;
        }
        return res[pnt];
    }
};
