// 1561. Maximum Number of Coins You Can Get

#include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles)
    {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int ans = 0;
        for(int i=n/3;i<n;i=i+2)
        {
            ans = ans + piles[i];
        }
        return ans;
       
    }
};