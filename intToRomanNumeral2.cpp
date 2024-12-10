class Solution {
public:
    string intToRoman(int num) {
        const std::vector<std::pair<int, std::string>> pairings{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}
        };

        std::string res;

        for (const std::pair<int, std::string>& pairing : pairings) {
            if (num == 0) {
                break;
            }

            while (num >= pairing.first) {
                res += pairing.second;
                num -= pairing.first;
            }
        }

        return res;
    }
};
