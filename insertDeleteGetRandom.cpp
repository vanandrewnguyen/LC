class RandomizedSet {
public:
    std::set<int> s;

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (s.count(val)) {
            return false;
        }

        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (s.count(val)) {
            s.erase(val);
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        int ind = std::rand() % s.size();
        return *(std::next(s.begin(), ind));
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
