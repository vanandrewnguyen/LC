class RecentCounter {
public:
    std::queue<int> q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int numReq = t - 3000, c = 0;
        q.push(t);

        while (!q.empty()) {
            if (q.front() < numReq) {
                q.pop();
            } else {
                break;
            }
        }

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
