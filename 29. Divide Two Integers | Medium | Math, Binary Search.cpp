/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int sgn = -1, res = 0;
        if (dividend > 0) {
            dividend *= -1;
            sgn *= -1;
        }
        if (divisor > 0) {
            divisor *= -1;
            sgn *= -1;
        }
        while (dividend <= divisor) {
            int tmp = divisor, delta = -1;
            while (dividend - tmp < tmp) {
                tmp *= 2;
                delta *= 2;
            }
            dividend -= tmp;
            res += delta;
        }
        return res*sgn;
    }
};
