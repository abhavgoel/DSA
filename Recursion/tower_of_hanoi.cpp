#include<bits/stdc++.h>
using namespace std;

void toh(int n,string source,string destination,string helper)
{
    if(n==1)
    {
    cout<<"moving disc "<<1<<" from "<<source<<" to "<<destination<<endl;
    return;
    }

    toh(n-1,source,helper,destination);
    cout<<"moving disc "<<n<<" from "<<source<<" to "<<destination<<endl;
    toh(n-1,helper,destination,source);
}
int main()
{
    cout<<"enter the number of disks ";
    int n;
    cin>>n;
    string source ="A";
    string destination="C";
    string helper="B";
    toh(n,source,destination,helper);
}