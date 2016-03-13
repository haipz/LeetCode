/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        // Manacher -- BEGIN
        string p = "$#" + s + s;
        for (int i = 0; i < s.size(); ++i) {
            p[i*2 + 2] = s[i];
            p[i*2 + 3] = '#';
        }
        vector<int> mp(s.size()*2 + 2, 0);
        int mx = 0, idx = 0;
        // mx(boundary), idx(center)
        for (int i = 0; i < s.size()*2 + 2; ++i) {
            // idx*2 - i(mirror) <--> id <--> i(original)
            mp[i] = mx > i ? min(mp[idx*2 - i], mx - i) : 1;
            while (p[i + mp[i]] == p[i - mp[i]]) {
                ++mp[i];
            }
            // update boundary value and center index
            if (i + mp[i] > mx) {
                mx = i + mp[i];
                idx = i;
            }
        }
        // Manacher -- END
        // find the index of the longest palindromic substring
        mx = 0;
        for (int i = 0; i < s.size()*2 + 2; ++i) {
            if (mp[i] - 1 >= mx) {
                mx = mp[i] - 1;
                idx = i;
            }
        }
        if (mx & 1) {
			return s.substr(idx/2 - (mx + 1)/2, mx);
		} else {
        	return s.substr(idx/2 - mx/2, mx);
        }
    }
};
