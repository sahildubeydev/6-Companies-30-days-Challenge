// 2428. Maximum Sum of an Hourglass

#include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<m-2;j++)
            {
                int res=0;
                for(int c=j;c<j+3;c++)
                {
                    res+=grid[i][c]; // first row 
                    res+=grid[i+2][c]; // 3rd row
                }
                res+=grid[i+1][j+1];
                ans=max(ans,res);
            }
        }
        return ans;
    }
};