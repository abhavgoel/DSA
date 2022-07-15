#include<bits/stdc++.h>
using namespace std;

//concatenate the string s1
//and find the pattern in the string


bool areRotations(string s1,string s2)
{
    if(s1.length()!=s2.length())
        return false;
    return ((s1+s1).find(s2)!=string::npos);//npos - end of string
}
 
int main() 
{ 
    string s1 = "ABCD";string s2="CDDB";
    if(areRotations(s1,s2)){cout<<"Strings are rotations of each other"<<endl;}
    else{cout<<"Strings are not rotations of each other"<<endl;}
    
    return 0; 
} 