class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
    }
    
    void push(int value) {
        int minn = (minst.empty())?INT_MAX:minst.top();
        minn = min(minn,value);
        st.push(value);
        minst.push(minn);
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */