#include<iostream>
#include<vector>
#include<vector>
#include<algorithm>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum +=nums[i];
        }
        int totalSum = (nums.size()*(1+nums.size()))/2;
        return totalSum - sum;
    }
};

int main(){}