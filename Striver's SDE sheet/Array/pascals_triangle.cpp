#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle;

        for(int i=0;i<numRows;i++)
        {
            vector<int>row(i+1,1);
            for(int j=1;j<i;j++)//this loop starts from i=2
            {
                row[j] = triangle[i-1][j] + triangle[i-1][j-1];
            }
            triangle.push_back(row);
            
        }
        return triangle;
    }
};