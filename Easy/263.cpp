/****************************************************************
 *
 * LeetCode 263. Ugly Number
 *
 * *************************************************************/


class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        const int primes[] = { 2, 3, 5 };

        for (int p : primes) while (n % p == 0) n /= p;

        return n == 1;
    }
};