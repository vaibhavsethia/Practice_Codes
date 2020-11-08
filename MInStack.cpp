class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    MinStack() {

    }

    void push(int x) {
        st.push(x);
    }

    void pop() {
        st.pop();
    }

    int top() {
        if(!st.empty())
            return st.top();
        return INT_MIN;
    }

    int getMin() {
        int minVal=INT_MAX;
        stack<int> temp;
        temp=st;
        while(!temp.empty()){
            int present = temp.top();
            minVal=(present<minVal)?present:minVal;
            temp.pop();
        }
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */