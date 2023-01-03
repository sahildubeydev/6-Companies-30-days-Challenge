// 207. Course Schedule

#include<vector>
#include<queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i=0;i<prerequisites.size();i++) 
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        vector<int> topo;
        vector<int> in(numCourses,0);
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            for(auto j:adj[i]) in[j]++;
        }

        for(int node=0;node<numCourses;node++){
            if(!in[node]) q.push(node);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:adj[node]){
                in[i]--;
                if(!in[i]) q.push(i);
            }
        }
        return topo.size()==numCourses;
    }