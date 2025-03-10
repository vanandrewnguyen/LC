// 1780
class Solution {
public:
    bool checkPowersOfThree(int n) {
        return doCheck(0, n);
    }

    bool doCheck(int power, int n) {
        if (n == 0) { return true; } // found it
        int p = std::pow(3, power);
        if (p > n) { return false; } // exceeded n
        return (doCheck(power+1, n-p)) || (doCheck(power+1, n)); // include or skip answer, diverging paths
    }
};
