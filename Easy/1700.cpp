#include <iostream>
#include <vector>

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int countZero = 0, countOne = 0;

        // Count the number of students preferring square (0) and circular (1) sandwiches
        for (int student : students) {
            if (student == 0) countZero++;
            else countOne++;
        }

        // Try to serve each sandwich
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (countZero > 0) {
                    countZero--;  // A student preferring square sandwich takes it
                }
                else {
                    break;  // No more students preferring square sandwiches
                }
            }
            else {
                if (countOne > 0) {
                    countOne--;  // A student preferring circular sandwich takes it
                }
                else {
                    break;  // No more students preferring circular sandwiches
                }
            }
        }

        // The number of students left without sandwiches is the sum of countZero and countOne
        return countZero + countOne;

    }
};

