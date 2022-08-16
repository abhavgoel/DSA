#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<long long int>s;
    long long int minele;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.size()==0)
        {
            s.push(val);
            minele=val;
            
        }
        else
        {
            if(val>=minele)
                s.push(val);
            else if(val<minele)
            {
                s.push((long long int)2*val-minele);
                minele=val;
            }
        }
    }
    
    void pop() {
        if(s.size()==0)
            return ;
        else if(s.top()>=minele)
            s.pop();
        else if(s.top()<minele)
        {
            minele=2*minele-s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.size()==0)
            return -1;
        else
        {
            if(s.top()>=minele)
                return s.top();
            else 
            {
                return minele;
            }
        }
    }
    
    int getMin() {
        if(s.size()==0)
            return -1;
        return minele;
        
    }
};

