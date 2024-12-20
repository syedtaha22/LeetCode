/****************************************************************
 *
 * LeetCode 74. Search a 2D Matrix
 *
 * *************************************************************/

#include<vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int row = mid / n, col = mid % n;

            if (matrix[row][col] < target) {
                left = mid + 1;
            }
            else if (matrix[row][col] > target) {
                right = mid - 1;
            }
            else return true;
        }
        return false;
    }
};