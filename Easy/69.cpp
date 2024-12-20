/****************************************************************
 *
 * LeetCode 69. Sqrt(x)
 *
 * *************************************************************/

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        long left = 0;
        long right = x;
        long result = 0;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid;

            if (square == x) return mid;
            else if (square < x) {
                result = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return result;
    }
};