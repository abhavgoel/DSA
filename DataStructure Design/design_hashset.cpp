#include<bits/stdc++.h>
using namespace std;
//we will use separate chaining for designing a hashset
//first we take a vector of vector to store the chains
//then taking modulo of the key with

class MyHashSet {
public:
vector<vector<int>>buckets;
int M;
    MyHashSet() {
        M=10000;
        buckets = vector<vector<int>>(M,vector<int>());
    }
    int getIndex(int key)
    {
        return key%M;
    }
    
    void add(int key) {
        int index = getIndex(key);
        auto it = find(buckets[index].begin(),buckets[index].end(),key);//searching in the chain

        if(it==buckets[index].end())//not present
        buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto it = find(buckets[index].begin(),buckets[index].end(),key);

        if(it!=buckets[index].end())//present then erase
        buckets[index].erase(it);

    }
    
    bool contains(int key) {
        int index = getIndex(key);
        auto it = find(buckets[index].begin(),buckets[index].end(),key);

        return it!=buckets[index].end();


    }
};