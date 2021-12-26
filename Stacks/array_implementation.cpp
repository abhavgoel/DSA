#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int *arr;
    int cap;
    int top;
    Stack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    bool push(int x)
    {
        if (top == (cap - 1))
        {
            cout << "Stack overflow, cannot push "<<x << endl;
            return false;
        }
        else
        {
            top++;
            arr[top] = x;
            return true;
        }
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        else
        {
            int res = arr[top];
            top--;
            return res;
        }
    }
    int peek()
    {
        return arr[top];
    }
    int size()
    {
        return (top + 1);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    Stack s(2);
    s.push(5);
    s.push(10);
    s.push(15);
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}
