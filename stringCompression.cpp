class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() < 2) { return chars.size(); }

        int modifyIndex = 0;
        int readIndex = 0;

        while (readIndex < chars.size()) {
            chars[modifyIndex] = chars[readIndex];

            int count = 0;
            while (readIndex < chars.size() && chars[readIndex] == chars[modifyIndex]) {
                count++;
                readIndex++;
            }

            if (count == 1) {
                modifyIndex++;
            } else {
                std::string str = std::to_string(count);
                modifyIndex++;
                for (char& digit : str) {
                    chars[modifyIndex++] = digit;
                }
            }
        }

        for (int i = 0; i < chars.size(); i++) {
            std::cout << chars[i] << std::endl;
        }

        return modifyIndex;
    }
};
