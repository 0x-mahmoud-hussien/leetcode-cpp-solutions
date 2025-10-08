
// https://leetcode.com/problems/implement-queue-using-stacks
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {
    }
    
    void push(int x) 
    {
        s1.push(x);
    }
    
    int pop() 
    {
        if (s2.empty()) 
        {
            while (!s1.empty()) 
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int front = s2.top();
        s2.pop();
        return front;
    }
    
    int peek() 
    {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() 
    {
        return s1.empty() && s2.empty();
    }
};

int main() 
{
    MyQueue* obj = new MyQueue();
    
    obj->push(10);
    obj->push(20);
    obj->push(30);
    
    cout << "Front element: " << obj->peek() << endl; 
    cout << "Pop element: " << obj->pop() << endl;   
    cout << "Front element now: " << obj->peek() << endl; 
    
    obj->push(40);
    cout << "Pop element: " << obj->pop() << endl; 
    cout << "Pop element: " << obj->pop() << endl; 
    cout << "Is empty? " << (obj->empty() ? "Yes" : "No") << endl;
    
    obj->pop(); 
    cout << "Is empty now? " << (obj->empty() ? "Yes" : "No") << endl; 
    
    delete obj;
    return 0;
}