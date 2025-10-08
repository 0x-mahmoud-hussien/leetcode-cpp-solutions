
// https://leetcode.com/problems/min-stack
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;  
    stack<int> minStack;   

public:
    MinStack() {}

    void push(int val) 
    {
        mainStack.push(val);

        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }

    void pop() 
    {
        if (mainStack.top() == minStack.top())
            minStack.pop();
        mainStack.pop();
    }

    int top() 
    {
        return mainStack.top();
    }

    int getMin() 
    {
        return minStack.top();
    }
};

int main() 
{
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Current minimum: " << st.getMin() << endl; 

    st.pop();  
    cout << "New minimum after pop: " << st.getMin() << endl;  

    cout << "Top element: " << st.top() << endl;  

    return 0;
}