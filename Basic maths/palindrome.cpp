#include<bits/stdc++.h>
using namespace std;
bool isPalin(int n)
{
    int temp,rev=0,ld;
    temp=n;
    while(temp!=0)
    {
        ld=temp%10;
        rev=rev*10+ld;
        temp=temp/10;
    }
    return (rev==n);
}

int main()
{
    int n;
    cin>>n;
    isPalin(n);
    if (isPalin(n)==true)
    {
        cout<<"Number is palindrome"<<endl;
    }
    else cout<<"Not palindrome"<<endl;

    return 0;
}