/****************************************************************
 *
 * LeetCode 20. Valid Parentheses
 *
 * *************************************************************/
#include <iostream>
#include <stack>

class Solution {
private:

    int cmap(char character) {
        switch (character) {
        case '[': return 1;
        case '{': return 2;
        case '(': return 3;
        case ']': return -1;
        case '}': return -2;
        case ')': return -3;
        default: return 0;
        }
    }

public:
    bool isValid(std::string s) {
        if (s.empty()) return true;
        std::stack<char> stk;
        for (char c : s) {
            int bracket = cmap(c);
            if (bracket > 0) stk.push(bracket);
            else {
                if (stk.empty() || stk.top() * -1 != bracket) return false;
                else stk.pop();
            }
        }
        return stk.size() <= 0;
    }
};