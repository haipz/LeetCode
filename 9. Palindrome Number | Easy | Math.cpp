/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int _x = x, t = 0;
        while (_x) {
            t = t*10 + _x % 10;
            _x /= 10;
        }
        return t == x;
    }
};
