// 481. Magical String

#include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
    
    // if n is less than or equal to 3 then cnt of one is 1 
    if(n<=3){
        return 1;
    }
    
    // take a initial string "122"
    
    string s = "122";
    
    int i=2;    // 'i' point the curr index and according to that index we add on back of the string 
    int j=2;    // 'j' point the last index of a string if at last index '1' occur then we can only add '2' else if at last index '2' present then we can add '1'
    int cnt = 0;
    
    while(j<n){
        if(s[i]=='1'){
            if(s[j]=='1'){
                s+="2";
            }
            else{
                s+="1";
            }
            j++;
        }
        else{
            if(s[j]=='1'){
                s+="22";
            }
            else{
                s+="11";
            }
            j+=2;
        }
        i++;
    }
    // count the occurrrence of an one in string s
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cnt++;
        }
    }
   
    return cnt;
}
};