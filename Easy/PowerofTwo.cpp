#include<iostream>
#include<cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n % 2 == 0) { n = n / 2; }

        if (n == 1) return true;
        else return false;
    }
};


int main(){

    Solution s;
    for (int i = 0; i <= 200; i++){
        if (s.isPowerOfTwo(i)) std::cout << i << " ";
    }

}