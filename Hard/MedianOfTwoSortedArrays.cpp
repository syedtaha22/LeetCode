#include<iostream>
#include<vector>
#include<algorithm>


class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

        std::vector<int> merged;
        for(int i = 0; i < nums1.size(); i++){
            merged.push_back(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++){
            merged.push_back(nums2[i]);
        }
        std::sort(merged.begin(), merged.end());

        int total = merged.size();
        if(total % 2 != 0){
            return merged[((total+1)/2) - 1];
        }
        else{
            int middle1 = merged[total/2 - 1];
            int middle2 = merged[total/2];
            return (middle1 + middle2)/2.0;
        } 
    }
};

int main(){

    Solution s;

    std::vector<int> m = {1,2};
    std::vector<int> n = {4};
    std::cout << s.findMedianSortedArrays(n,m);


    return 0;
}