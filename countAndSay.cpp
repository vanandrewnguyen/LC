class Solution {
public:
    string countAndSay(int n) {
        int num = 1;
        std::string str;

        while (num <= n) {
            if (num == 1) {
                str = "1";
            } else {
                // Each iteration of n > 1
                int i = 0; 
                int count = 1;
                std::string tmp = "";
                // Iteratively loop down built string
                while (i < str.size()) {
                    // Update count
                    if (str[i] == str[i+1]) {
                        count++;
                    } else {
                        // append the occurance and char
                        tmp += char(count + '0');
                        tmp += str[i];
                        count = 1;
                    }
                    i++;
                }
                str = tmp;
            }
            
            num++;
        }

        return str;
    }
};
