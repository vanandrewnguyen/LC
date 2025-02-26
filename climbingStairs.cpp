class Solution {
public:
    int climbStairs(int n) {
        // from index 0..n, we recurse twice for n+1, n+2 until currIndex >= n
        // add this to an array such that we know the prev step
        std::map<int, int> mem;
        return doClimb(n, mem);
    }

    int doClimb(int n, std::map<int, int>& mem) {
        if (n <= 1) return 1;
        if (mem.find(n) != mem.end()) {
            return mem[n];
        }
        mem[n] = doClimb(n-1, mem) + doClimb(n-2, mem);
        return mem[n];
    }
};
