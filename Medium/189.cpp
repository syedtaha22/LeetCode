/****************************************************************
 *
 * LeetCode 189. Rotate Array
 *
 * *************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k = k % nums.size();; // Ensure k doesn't exceed array size
        if (k == 0) return; // No rotation needed

        // Step 1: Reverse the entire array
        std::reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        std::reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining elements
        std::reverse(nums.begin() + k, nums.end());
    }
};