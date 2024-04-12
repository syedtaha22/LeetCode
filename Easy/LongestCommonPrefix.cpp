#include<iostream>
#include<vector>


class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string result;
        for(int j = 0; j < strs[0].length(); j++){
            char current = strs[0][j];
            for(int i = 0; i < strs.size(); i++){
                if (strs[i][j] != current) return result;
            }
            result.push_back(current);
        }
        return result;
        
    }
};


int main() {}