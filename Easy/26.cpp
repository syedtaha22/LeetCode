/****************************************************************
 *
 * LeetCode 26. Remove Duplicates from Sorted Array
 *
 * *************************************************************/

#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty())
            return 0;

        // If size is not zero, there is atleast one unique element
        int k = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i])
                nums[k++] = nums[i];
        }

        return k;
    }
};