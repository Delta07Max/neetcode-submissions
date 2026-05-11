class MinStack {
public:
    stack<int> sstack;
    stack<int> minStack;
    MinStack()
    {
        
    }
    
    void push(int val)
    {
        sstack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop()
    {
        sstack.pop();
        minStack.pop();
    }
    
    int top()
    {
        return sstack.top();
    }
    
    int getMin()
    {
        return minStack.top();
    }
};
