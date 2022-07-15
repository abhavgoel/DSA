#include<bits/stdc++.h>
using namespace std;
#define CHAR 256

bool areSame(int ct[],int cp[])
{
    for(int i=0;i<CHAR;i++)
    {
        if(cp[i]!=ct[i])
        return false;
    }
    return true;
}

bool isPresent(string txt,string pat)
{
    int n=txt.length();
    int m=pat.length();
    int ct[CHAR]={0};
    int cp[CHAR]={0};
 

   for(int i=0;i<m;i++)
   {
    cp[pat[i]]++;
    ct[txt[i]]++;
    
   }

   for(int i=m;i<n;i++)
   {
    if(areSame(ct,cp))
    return true;
    ct[txt[i]]++;
    ct[txt[i-m]]--;
   }
   return false;

}

int main() 
{ 
    string txt = "geeksforgeeks"; 
    string pat = "frog"; 
    if (isPresent(txt,pat)) 
        cout << "Anagram search found"; 
    else
        cout << "Anagram search not found"; 
  
    return 0; 
} 