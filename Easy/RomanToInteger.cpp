#include<iostream>
#include<map>


class Solution {
public:

    int getSymbolValue(const char& symbol){
        switch (symbol){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }

    // int romanToInt(std::string s) {
    //     int convertedNumber = 0;
    //     char LastSymbol = ' ';
    //     std::map<char, int> SymbolsMap = {{'I', 1},{'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000 }};
    //     for(const char& currentSymbol : s){
    //         if(SymbolsMap[currentSymbol] > SymbolsMap[LastSymbol])
    //             { convertedNumber += SymbolsMap[currentSymbol] - (2 * SymbolsMap[LastSymbol]);}
    //         else convertedNumber += SymbolsMap[currentSymbol];
    //         LastSymbol = currentSymbol;
    //     }
    //     return convertedNumber;
    // }


    int romanToInt(std::string s) {
        int convertedNumber = 0;
        int index = 0;
        while(index < s.size()-1){
           if(getSymbolValue(s[index]) < getSymbolValue(s[index+1]))
              convertedNumber -= getSymbolValue(s[index]);
              else convertedNumber += getSymbolValue(s[index]);
              index++;
        }
        convertedNumber += getSymbolValue(s[index]);
        return convertedNumber;
    }
    
};


int main(){
    Solution s;

    std::string romanNumber = "MCMXCIV";
    std::cout << romanNumber << " = " << s.romanToInt(romanNumber) << std::endl;
}