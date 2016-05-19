/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
class Solution {
public:
    vector<int> next;
    
    void buildNext(string pattern) {
        next = vector<int>(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j >= 0 && pattern[j + 1] != pattern[i]) j = next[j];
            if (pattern[j + 1] == pattern[i]) ++j;
            next[i] = j;
        }
    }
    
    int runKMP(string text, string pattern) {
        if (pattern.empty()) return 0;
        buildNext(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j >= 0 && pattern[j + 1] != text[i]) j = next[j];
            if (pattern[j + 1] == text[i]) ++j;
            if (j + 1 == pattern.length()) return i - pattern.length() + 1;
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        return runKMP(haystack, needle);
    }
};
