/****************************************************************
 *
 * LeetCode 704. Binary Search
 *
 * *************************************************************/

#include<vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;
        while (left <= right) {
            mid = (right + left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else return mid;
        }
        return -1;
    }
};