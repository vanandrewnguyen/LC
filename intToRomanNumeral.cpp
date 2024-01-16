#define MAX_LEN 1000

class Solution {
public:
    string intToRoman(int num) {
        // Subtract largest possible roman numeral values until it is 0
        std::string str = "";
        while (num >= MAX_LEN) {
            str += 'M';
            num -= 1000;
        }

        std::map<int, std::string> m;
        m[900] = "CM";
        m[500] = "D";
        m[400] = "CD";
        m[100] = "C";
        m[90] = "XC";
        m[50] = "L";
        m[40] = "XL";
        m[10] = "X";
        m[9] = "IX";
        m[5] = "V";
        m[4] = "IV";
        m[1] = "I";

        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            cout << it->first << " = " << it->second << endl;
            // If number is a mulitple of 10 then we loop to subtract
            // E.g. 3 -> III, 30 -> XXX
            if (std::floor(log10(it->first)) == log10(it->first)) {
                while(num >= it->first){
                    str += it->second;
                    num -= it->first;
                }
            } else {
                // Where as non-powers of 10, e.g. 50 we can check once, e.g. LLL doesn't exist
                if (num >= it->first) {
                    str += it->second;
                    num -= it->first;
                }
            }
        }

        return str;
    }
};
