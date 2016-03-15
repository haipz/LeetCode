/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
class Solution {
public:
    bool match(char a, char b) {
        return a == '.' || a == b;
    }
    
    bool isMatch(string s, string p) {
        vector<bool> f(s.size(), false);
        f[0] = true;
        for (int i = 0; i < p.size(); ++i) {
            char ch = p[i];
            bool withstar = p[i + 1] == '*';
            if (withstar) ++i;
            if (withstar) {
                // if with star:
                // 1. match from f[j - 1] with one or more
                // 2. match none from f[j] self
                for (int j = 1; j <= s.size(); ++j) f[j] = f[j] || (f[j - 1] && match(ch, s[j - 1]));
            } else {
                // if no star:
                // 1. all patterns have to match this char
                // 2. f[0] equal to false because of it matchs none
                for (int j = s.size(); j > 0; --j) f[j] = f[j - 1] && match(ch, s[j - 1]);
                f[0] = false;
            }
        }
        return f[s.size()];
    }
};
