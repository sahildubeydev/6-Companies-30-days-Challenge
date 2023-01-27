// 1348. Tweet Counts Per Frequency

#include  <bits/stdc++.h>
using namespace std;

class TweetCounts {
public:
    unordered_map<string, int> convertToSeconds {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
    
    unordered_map<string, map<int,int>> mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string s, int time) {
        mp[s][time]++;
        return;
    }
    
    vector<int> getTweetCountsPerFrequency(string f, string s, int startTime, int endTime) {
        
        vector<int> ans;
        
        
        int secs = convertToSeconds[f];
        int slots = ((endTime - startTime + 1) + (secs-1))/secs;
        
        
        map<int,int>& temp = mp[s];
        
        for(int i=0;i<slots;i++){
            
            int start = secs*i + startTime;
            int end = min(endTime, start + secs-1);
            
            auto iterStart = temp.lower_bound(start);
            auto iterEnd = temp.upper_bound(end);
            
            int cnt = 0;
            for(auto iter = iterStart; iter != iterEnd; iter++)
                cnt += iter->second;
    
            ans.push_back(cnt);
        }
        
        return ans;
        
    }
};