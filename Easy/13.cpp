#include<map>
#include<string>

class Solution {
public:

    int getSymbolValue(const char& symbol) {
        switch (symbol) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
    }

    int romanToInt(std::string s) {
        int convertedNumber = 0;
        int index = 0;
        while (index < s.size() - 1) {
            if (getSymbolValue(s[index]) < getSymbolValue(s[index + 1]))
                convertedNumber -= getSymbolValue(s[index]);
            else convertedNumber += getSymbolValue(s[index]);
            index++;
        }
        convertedNumber += getSymbolValue(s[index]);
        return convertedNumber;
    }
};