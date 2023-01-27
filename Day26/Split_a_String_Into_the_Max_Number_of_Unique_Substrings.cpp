// 1593. Split a String Into the Max Number of Unique Substrings

#include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int n;
    string s;
    int res;
     set<string>ss; //to store current partitiond string
    int maxUniqueSplit(string g) {
        s=g;
        res=0;
        n=s.length();
       
        check(0);
        return res;
    }
    void check(int x)
    {
        if(x==n)
        {
            int r=ss.size();
            res=max(res,r); //store the max value
            return;
        }
        string g="";
       for(int i=x;i<n;i++)
       {
           g+=s[i]; // add next char to current partioned string 
           if(ss.find(g)==ss.end()) //if this string is unique
           {
               ss.insert(g); // store it in set 
               check(i+1); //backtrack with next index
               ss.erase(g);// remove from set so it may not effect upcoming checks 
           }
       }
    }
};
