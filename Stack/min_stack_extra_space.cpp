#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
stack<int>s;
    stack<int>ss;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        
        if(ss.size()==0 || ss.top()>=val)
            ss.push(val);
        return;
    }
    
    void pop() {
        if(s.size()==0)
            return;
        int ans=s.top();
        s.pop();
        if(ss.top()==ans)
            ss.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(ss.size()==0)
            return -1;
        return ss.top();
        
    }
};