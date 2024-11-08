/****************************************************************
 *
 * LeetCode 50. Pow(x, n)
 *
 * *************************************************************/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;

        double half = myPow(x, n / 2);

        if (n % 2) return (n > 0) ? (half * half * x) : (half * half / x);
        return half * half;
    }
};