class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }

        int len = flowerbed.size();
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (flowerbed[i] == 0) {
                int leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                int rightEmpty = (i == len - 1) || (flowerbed[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;
                    count++;

                    if (count >= n)
                        return true;
                }
            }
        }

        return false;
    }
};
