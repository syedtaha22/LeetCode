#include<iostream>
#include<vector>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string formatted = "";
        for(size_t i = 0; i < s.length() ; i++){ if(isalnum(s[i])) formatted += tolower(s[i]); }
        return formatted == std::string(formatted.rbegin(), formatted.rend());
    }
};

int main(){}