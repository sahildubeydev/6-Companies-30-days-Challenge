// 1358. Number of Substrings Containing All Three Characters

#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int left = 0 , right = 0 , end = s.size() - 1;
        unordered_map<char,int> map;
        
        int count = 0;
        
        while(right != s.size())
        {
            map[s[right]] += 1; // adding new element to window
            
            while(map['a'] and map['b'] and map['c']) // while(window is good)
            {
                count += 1 + (end - right);
                
				// removing first element[means shrinking window from front to form new window]
                map[s[left]] -= 1; 
                left++;
            }
            right++;
        }
        return count;
    }
};