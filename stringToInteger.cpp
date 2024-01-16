#include <string>

class Solution {
public:
    int myAtoi(string s) {
        bool isPositive = true;
        int index = 0;
        int size = s.size();
        double isolatedNumber = 0;

        // Skip leading whitespace
        while(s[index] == ' ') {
            index++;
        }

        // Keep track of whether result is pos/neg
        if (s[index] == '-' || s[index] == '+') {
            isPositive = (s[index] != '-');
            index++;
        }

        // Construct number in isolation
        while ((index < size) && (std::isdigit(s[index]))) {
            isolatedNumber = (isolatedNumber * 10) + (s[index] - '0');
            index++;
        }

        // Ensure we keep sign
        isolatedNumber *= (isPositive) ? 1 : -1;

        // Clamp
        if (isolatedNumber > INT_MAX) {
            isolatedNumber = INT_MAX;
        }
        if (isolatedNumber < INT_MIN) {
            isolatedNumber = INT_MIN;
        }

        return isolatedNumber;
    }
};
