/****************************************************************
 *
 * LeetCode 9. Palindrome Number
 *
 * *************************************************************/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0) return false;
        int n = x;
        long long flipped = 0;
        while (n > 0) {
            flipped = flipped * 10 + (n % 10);
            n /= 10;
        }
        return flipped == x;
    }
};