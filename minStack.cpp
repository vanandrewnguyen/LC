class MinStack {
private:
    std::stack<int> s, min;

public:
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if (min.size() == 0 || val <= min.top()) {
            // push when empty or lesser
            min.push(val);
        }
    }
    
    void pop() {
        if (min.top() == s.top()) {
            // -2, 0, -3, pop -3, then min should be -2
            min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
