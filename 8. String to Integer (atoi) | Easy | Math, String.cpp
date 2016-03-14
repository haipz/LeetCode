/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
*/
class Solution {
public:
    int myAtoi(string str) {
        int res = 0, sgn = 1;
        for (int i = 0; i < str.size(); ++i)
            if (str[i] == ' ') {
                str.erase(i, 1);
                --i;
            } else break;
        if (str[0] == '+') {
            sgn = 1;
            str.erase(0, 1);
        } else if (str[0] == '-') {
            sgn = -1;
            str.erase(0, 1);
        }
        int overflow = sgn > 0 ? INT_MAX : INT_MIN;
        for (int i = 0; i < str.size(); ++i)
            if (isdigit(str[i])) {
                int num = str[i] - '0';
                if ((long long)res*10 + num > INT_MAX) return overflow;
                res = res*10 + num;
            } else break;
        return sgn*res;
    }
};
