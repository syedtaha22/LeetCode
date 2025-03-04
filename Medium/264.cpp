/****************************************************************
 *
 * LeetCode 264. Ugly Number II
 *
 * *************************************************************/

#include <vector>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> dp(n);
        dp[0] = 1; // First ugly number is 1

        int i2 = 0, i3 = 0, i5 = 0;  // Pointers for multiples of 2, 3, and 5
        int next2 = 2, next3 = 3, next5 = 5;

        for (int i = 1; i < n; ++i) {
            int nextUgly = std::min({ next2, next3, next5 });
            dp[i] = nextUgly;

            // Move the pointer that generated this ugly number
            if (nextUgly == next2) next2 = 2 * dp[++i2];
            if (nextUgly == next3) next3 = 3 * dp[++i3];
            if (nextUgly == next5) next5 = 5 * dp[++i5];
        }

        return dp[n - 1];  // The nth ugly number
    }
};