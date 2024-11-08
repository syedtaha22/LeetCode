/****************************************************************
 *
 * LeetCode 169. Majority Element
 *
 * *************************************************************/

#include<vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int cnt = 0, ele = 0;

        for (int i = 0; i < nums.size(); i++) {
            ele = (cnt == 0) ? nums[i] : ele;
            cnt += (nums[i] == ele) ? 1 : -1;
        }
        return ele;
    }
};