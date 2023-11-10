class Solution {
public:
    vector<int>ans;
    void dfs(int node,unordered_map<int,vector<int>>&adj,unordered_set<int>&vis){
        vis.insert(node);
        ans.push_back(node);
        for(auto i : adj[node]){
            if(!vis.count(i)) dfs(i,adj,vis);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>adj;
        unordered_set<int>vis;
        for(auto i : adjacentPairs){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int a;
        for(auto i : adj){
            if(i.second.size()==1) {a = i.first;break;}
        }
        dfs(a,adj,vis);
        return ans;
    }
};