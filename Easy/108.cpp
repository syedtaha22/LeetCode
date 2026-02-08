/****************************************************************
 *
 * LeetCode 108. Convert Sorted Array to Binary Search Tree
 *
 * *************************************************************/

#include<iostream>
#include<vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

    TreeNode* insert(std::vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr; // Base Case: no more numbers, return nullptr

        int mid = (left + right) / 2; // Compute the mid point

        TreeNode* node = new TreeNode(nums[mid]); 
        node->left = insert(nums, left, mid);
        node->right = insert(nums, mid + 1, right);
        return node;
    }


public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) { return insert(nums, 0, nums.size()); }
};
