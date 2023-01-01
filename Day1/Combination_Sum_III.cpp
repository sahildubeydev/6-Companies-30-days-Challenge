// 216. Combination Sum III

#include <vector>
using namespace std;

vector<vector<int>> ans;
    void help(int i, int t, vector<int>&sol, int k){
        if(t==0 && k==0){
            ans.push_back(sol);
            return;
        }
        if(t<0 || k<0){
            return;
        }
        if(i==10){
            return;
        }
        // skip the i'th element
        help(i+1, t, sol, k);

        // pick the i'th element
        sol.push_back(i);
        help(i+1, t-i, sol, k-1);

        // backtracking
        sol.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> sol;
        help(1, n, sol, k);
        return ans;
    }