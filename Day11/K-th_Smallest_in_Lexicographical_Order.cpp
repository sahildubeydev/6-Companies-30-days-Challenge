// 440. K-th Smallest in Lexicographical Order

#include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k)
    {
        int result = 1;
        for(--k; k > 0; )
        {
            int count = 0;
            for (long long first = static_cast<long long>(result), last = first + 1;
                first <= n; // the interval is not empty
                first *= 10, last *= 10) // increase a digit
            {
                // valid interval = [first, last] union [first, n]
                count += static_cast<int>((min(n + 1LL, last) - first)); // add the length of interval
            }
            
            if (k >= count)
            {   
                // increase the current prefix
                ++result;
                k -= count;
            }
            else
            {   // not able to skip all of
                // search more detailedly
                result *= 10;
                --k;
            }
        }
        return result;
    }
};