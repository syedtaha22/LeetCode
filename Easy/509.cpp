/****************************************************************
 *
 * LeetCode 509. Fibonacci Number
 *
 * *************************************************************/

#include<iostream>
#include<vector>

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        std::vector<int> fibSequence{ 0,1 };
        for (int i = 2; i <= n; i++) {
            fibSequence.push_back(fibSequence[i - 1] + fibSequence[i - 2]);
        }
        return fibSequence[n];
    }
};


