#include<bits/stdc++.h>
using namespace std;
#define mod 101
#define d 256

void rabinKarp(string &pat,string &txt,int m,int n)
{
    int i=0;
    int j=0;
    int p=0;//hash value for pattern
    int t=0;//hash value for text

    int h=1;
    for(int i=1;i<=m-1;i++)
    h=(h*d)%mod;
    
    for(int i=0;i<m;i++)
    {
        p=(p*d+pat[i])%mod;
        t=(t*d+txt[i])%mod;
    }

    while(i<=n-m)
    {
        
        if(j-i+1<m)
        j++;//window size <m
        else if(j-i+1==m)
        {
            if(p==t)
            {
                bool flag=true;
                for(int k=0;k<m;k++)
                {
                    if(txt[i+k]!=pat[k])//check for spurious hits
                    {
                         flag=false;
                         break;
                    }
                   
                }
                if(flag==true)
                   cout<<i<<" ";
            }
            t=(d*(t-txt[i]*h)+txt[i+m])%mod;//remove starting element and addinf last one
            if(t<0)
                t=t+mod;
            
            //slide the window
            i++;
            j++;

        }
    }
}
int main() 
{ 
    string txt;
    cin>>txt;
    string pat;
    cin>>pat;
    cout<<"All index numbers where pattern found:"<<" ";
    rabinKarp(pat,txt,pat.size(),txt.size());
    
    return 0; 
} 