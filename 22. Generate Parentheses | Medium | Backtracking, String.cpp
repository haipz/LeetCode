/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
public:
    vector<string> res;
    string tmp;
    void dfs(int dep, int cnt, int n) {
        if (dep == n) {
            res.push_back(tmp);
            return;
        }
        if (cnt > 0) {
            if (tmp.size() > dep) tmp[dep] = ')';
            else tmp += ')';
            dfs(dep + 1, cnt - 1, n);
        }
        if (n - dep - 1 >= cnt + 1) {
            if (tmp.size() > dep) tmp[dep] = '(';
            else tmp += '(';
            dfs(dep + 1, cnt + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n*2);
        return res;
    }
};
