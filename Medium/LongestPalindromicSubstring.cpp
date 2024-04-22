#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.length();
        if (n <= 1) return s;

        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        int start = 0, maxLen = 1;

        // Initialize one and two character palindromes
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if (i < n - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check palindromes of length > 2
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main(){}




    