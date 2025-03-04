/****************************************************************
 *
 * LeetCode 1768. Merge Strings Alternately
 *
 * *************************************************************/

#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string result;
        int i = 0, j = 0;

        while (i < word1.size() || j < word2.size()) {
            if (i < word1.size()) result += word1[i++];
            if (j < word2.size()) result += word2[j++];
        }
        return result;
    }
};