#include<bits/stdc++.h>
using namespace std;
//IN THIS EFFICIENT SOLUTION WE CAN COUNT THE NUMBER OF 2'S AND 5'S IN THE PRIME FACTORIZATION OF THE NUMBER
int trailZeros(int n)
{
    int fact=1;
    for(int i=2;i<=n;i++)
    {
        fact=fact*i;
    }
    int res=0;
    for (int i=5;i<=n;i=i*5)
    {
        res=res+n/i; //here in the prime factorisation number of 2's will always be greater than number of 5's...so we counter the number of time 5 comes in the prime factorisation of a number 
    }
    return res;
    //its time complexity is logn

}
int main()
{
    int n;
    cin>>n;
    cout<<trailZeros(n);
    return 0;
}