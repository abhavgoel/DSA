#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test int t;cin>>t;while(t--)
using namespace std;


//the questions states to perform operations 0,1,2 etc in range of queries
//ie if query = 0,3 ,  we have to do operations 0,1,2,3 in the array
void solve()

{
	ll n,m,k;
	cin>>n>>m>>k;
	int arr[n];
	//n = size of array
	//m = number of operations
	//k = queries
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll diff_array[n]={0};
	unordered_map<ll,vector<ll>>mp;
	for(int i=0;i<m;i++)
	{
		ll l,r,d;
		cin>>l>>r>>d;
		mp[i] = {l-1,r-1,d};

	}
	//make a new array to keep track of how many times a operation has to done
	ll operations[m]={0};//of size m, same as mp

	for(int i=0;i<k;i++)
	{
		ll l,r;
		cin>>l>>r;
		operations[l-1]++;
		if(r-1+1<m)
		operations[r-1+1]--;


	}

	for(int i=1;i<m;i++)
		operations[i]+=operations[i-1];

	//operations array stores how many times operation[i] has to be applied
	for(int i=0;i<m;i++)
	{
		mp[i][2] = mp[i][2]*operations[i];//updating the d by which now we have to update array
		//which is nothing but the frequency of the operations to be applied so we multiply
	}

	for(int i=0;i<m;i++)
	{
		ll l = mp[i][0];
		ll r = mp[i][1];
		ll d = mp[i][2];

		diff_array[l]+=d;
		if(r+1<n)
			diff_array[r+1]-=d;
	}

	for(int i=1;i<n;i++)
	{
		diff_array[i]+=diff_array[i-1];
	}
	for(int i=0;i<n;i++)
		cout<<diff_array[i]+arr[i]<<" ";




}
int main()
{
    flash
    //test
    solve();
   	return 0;
}