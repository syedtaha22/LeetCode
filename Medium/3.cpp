/****************************************************************
 *
 * LeetCode 3. Longest Substring Without Repeating Characters
 *
 * *************************************************************/


#include<unordered_map>
#include<string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charIndex;
        int maxLenght = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            if (charIndex.find(s[right]) != charIndex.end()) {
                left = std::max(left, charIndex[s[right]] + 1);
            }

            charIndex[s[right]] = right;
            maxLenght = std::max(maxLenght, right - left + 1);

        }
        return maxLenght;
    }
};