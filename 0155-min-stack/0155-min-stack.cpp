class MinStack
{
private:
    stack<int> mnAtThisPoint;
    stack<int> st;
    int mnSoFar = INT32_MAX;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        mnSoFar = min(mnSoFar, val);
        mnAtThisPoint.push(mnSoFar);
    }

    void pop()
    {
        st.pop();
        mnAtThisPoint.pop();
        !mnAtThisPoint.empty() ? mnSoFar = mnAtThisPoint.top() : mnSoFar = INT32_MAX;


    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return mnAtThisPoint.top();
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