class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min.push(INT_MAX);
    }
    
    void push(int x) {
        main.push(x);
        if (x <= min.top())  min.push(x);
    }
    
    void pop() {
        if (main.top() == min.top())
            min.pop();
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> main;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */