//each node carries a sum.
//root node - -carries sum of whole array
//child nodes carries sum of half range;
#include<bits/stdc++.h>
using namespace std;

class SegTree {

    public:
    vector<int>segTree;
    vector<int>nums;
    SegTree(vector<int>&nums) {
        segTree.resize(2*nums.size());
        this->nums = nums;
    }

    void buildTree(int i , int l, int r) { //O(N) - visiting all nodes only once
        if(l==r) {
            segTree[i] = nums[r];
            return ;
        }

        int mid = l + (r-l)/2;
        buildTree(2*i+1 , l,mid);
        buildTree(2*i+2, mid+1 ,r);

        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }

    void updateTree(int idx, int val, int i, int l, int r) {
          //This will update the tree in O(log N) time

        if(l==r) { //reached our index to update in the segTree array
            segTree[i] = val;
            return ;
        }

        int mid= l + (r-l)/2;
        if(idx <= mid) { //if the index to update is less than the mid of a range, it clearly would lie in the left subtree
            //we goto left subtree
            updateTree(idx,val,2*i + 1, l ,mid);

        } else {
            //we goto right subtree
            updateTree(idx,val,2*i + 2, mid+1, r);
        }

        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }

  
    int query(int start, int end, int i, int l, int r) {//(start,end) -> our range query, {l,r} -> range of nodes in the tree
        if(l > end || r < start) {
            return 0;
        }
        if(l>= start && r <= end) {
            return segTree[i];
        }
        else {
            int mid = l + (r-l)/2;

            return query(start,end, 2*i + 1, l , mid) + query(start,end, 2*i + 2, mid+1, r);
        }
    }

};

int main() {
    vector<int> nums = {3,1,2,7};

    SegTree stree(nums);
    stree.buildTree(0,0,nums.size()-1);

    // stree.updateTree(1,2,0,0,3);
    //    for(auto i : stree.segTree) {
    //     cout<<i<<" ";
    // }

    cout<<stree.query(1,2,0,0,3);


}