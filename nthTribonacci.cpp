class Solution {
public:
    int tribonacci(int n) {
        std::vector<int> mem((n>2) ? n+1 : 3, -1);
        mem.at(0) = 0;
        mem.at(1) = 1;
        mem.at(2) = 1;
        return find(n, mem);
    }

    int find(int n, std::vector<int>& mem) {
        if (mem[n] != -1) {
            return mem[n];
        }
        mem[n] = find(n-1, mem) + find(n-2, mem) + find(n-3, mem);
        return mem[n];
    }
};
