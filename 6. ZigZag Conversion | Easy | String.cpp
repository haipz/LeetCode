/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() < 3) return s;
        string t = s;
        int n = s.size(), idx = 0, l = (numRows - 1)*2, r = 0;
        for (int i = 0; i < numRows; ++i) {
            int j = i;
            t[idx++] = s[j];
            while (j < n) {
                j += l;
                if (l && j < n) {
                    t[idx++] = s[j];
                }
                j += r;
                if (r && j < n) {
                    t[idx++] = s[j];
                }
            }
            l -= 2;
            r += 2;
        }
        return t;
    }
};
