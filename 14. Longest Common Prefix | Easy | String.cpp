/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string("");
        int mx = 0;
        for (int i = 0; i < strs[0].size(); ++i) {
            bool flag = true;
            for (int j = 0; j < strs.size(); ++j)
                if (strs[j].size() < i || strs[j][i] != strs[0][i]) {
                    flag = false;
                    break;
                }
            if (!flag) break;
            ++mx;
        }
        return strs[0].substr(0, mx);
    }
};
