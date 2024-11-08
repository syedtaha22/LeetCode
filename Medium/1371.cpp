/*****************************************************************************
 *
 * LeetCode 1371. Find the Longest Substring Containing Vowels in Even Counts
 *
 * **************************************************************************/

#include <string>
#include <unordered_map>

class Solution {
public:
    int findTheLongestSubstring(std::string_view s) {
        // Map to track the first occurrence of each bitmask
        std::unordered_map<int, int> seen;
        seen[0] = -1;  // Initialize with the bitmask 00000 at index -1 (starting point)

        int bitmask = 0;  // Current bitmask
        int maxLength = 0;

        // Iterate through the string
        for (int i = 0; i < s.length(); ++i) {
            // Update the bitmask depending on the current character
            if (s[i] == 'a') bitmask ^= (1 << 0);
            else if (s[i] == 'e') bitmask ^= (1 << 1);
            else if (s[i] == 'i') bitmask ^= (1 << 2);
            else if (s[i] == 'o') bitmask ^= (1 << 3);
            else if (s[i] == 'u') bitmask ^= (1 << 4);

            // If we have seen this bitmask before, calculate the length of the substring
            if (seen.find(bitmask) != seen.end()) {
                maxLength = std::max(maxLength, i - seen[bitmask]);
            }
            else {
                // Otherwise, record the first occurrence of this bitmask
                seen[bitmask] = i;
            }
        }

        return maxLength;
    }
};