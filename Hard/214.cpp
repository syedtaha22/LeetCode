/****************************************************************
 *
 * LeetCode 214. Shortest Palindrome
 *
 * *************************************************************/

#include <string>
#include <vector>
#include <algorithm> // for reverse function

class Solution {
private:
    // Function to compute the prefix function (KMP table)
    void computePrefixFunction(const std::string& pattern, std::vector<int>& lps) {
        int m = pattern.size();
        lps[0] = 0; // Base case
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                ++len;
                lps[i] = len;
                ++i;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    ++i;
                }
            }
        }
    }

public:
    std::string shortestPalindrome(const std::string& s) {
        if (s.empty()) return s; // Edge case: if the string is empty

        // Create the combined string which is s + '#' + reverse(s)
        std::string rev_s(s);
        std::reverse(rev_s.begin(), rev_s.end());
        std::string combined = s + "#" + rev_s;

        // Compute the prefix function (KMP table)
        int n = combined.size();
        std::vector<int> lps(n, 0);
        computePrefixFunction(combined, lps);

        // The length of the longest palindrome prefix is stored in the last value of the lps array
        int longest_palindrome_prefix = lps.back();

        // We need to prepend the reverse of the remaining suffix to the original string
        std::string remaining_suffix = s.substr(longest_palindrome_prefix);
        std::reverse(remaining_suffix.begin(), remaining_suffix.end());

        // Construct and return the shortest palindrome
        return remaining_suffix + s;
    }
};
