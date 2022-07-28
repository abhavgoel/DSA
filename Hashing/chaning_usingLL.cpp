#include<bits/stdc++.h>
using namespace std;

struct myHash
{
    int BUCKET;
    list<int> *table;
    myHash(int b)
    {
        BUCKET=b;
        table=new list<int> [b]; //pointing to an array of size b
        //each element in array "table" is list<int>

    }

    void insert(int key)
    {
        int i=key%BUCKET;
        table[i].push_back(key);
    }
    void remove(int key)
    {
        int i=key%BUCKET;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i=key%BUCKET;

        for(auto x:table[i])
        {
            if(x==key)
            return true;
        }
        return false;
    }
};

	int main() 
	{ 
	    myHash mh(7);
	    mh.insert(10);
	    mh.insert(20);
	    mh.insert(15);
	    mh.insert(7);
	    cout << mh.search(10) << endl;
	    mh.remove(15);
	    cout << mh.search(15);
	} 