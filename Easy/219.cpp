/****************************************************************
 *
 * LeetCode 219. Contains Duplicate II
 *
 * *************************************************************/

#include<vector>
#include<unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> numIndexMap;

        for (int i = 0; i < nums.size(); ++i) {
            if (numIndexMap.find(nums[i]) != numIndexMap.end() && std::abs(i - numIndexMap[nums[i]]) <= k) {
                return true;
            }
            numIndexMap[nums[i]] = i;
        }
        return false;
    }
};