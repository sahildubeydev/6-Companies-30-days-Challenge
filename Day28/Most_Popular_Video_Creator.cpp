// 2456. Most Popular Video Creator

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) 
    {
        int n = ids.size();
        map<string, vector<pair<int, string>>>mp1; //creator => {views, ids}
        map<string, long long>mp2;  //creator => popularity
        for (int i = 0; i < n; i++)
        {
            mp2[creators[i]] += views[i]; //sum all views of a creator [Popularity]
            mp1[creators[i]].push_back({views[i], ids[i]}); 
        }
        //=================================
        long long mxPopularity = 0; //maximum Popularity
        for (auto it : mp2)
        {
            long long popularity = it.second;
            mxPopularity = max(mxPopularity, popularity);
        }
        //========================================
        vector<vector<string>>ans;
        for (auto it : mp2)
        {
            string creator = it.first;
            long long popularity = it.second;
            if (popularity == mxPopularity)
            {
                //sort all the videos of curr creator in decreasing order of views
                //if views same,  sort on basis of lexicographic order of ids
                sort(mp1[creator].begin(), mp1[creator].end(), [](pair<int, string>& a, pair<int, string>& b)->bool{
                    if (a.first > b.first) return true;
                    else if (a.first < b.first) return false;
                    else return (a.second < b.second);
                });
                string mostViewed = mp1[creator][0].second;
                ans.push_back({creator, mostViewed});
            }
        }
        //===============================================
        return ans;
        
    }
};