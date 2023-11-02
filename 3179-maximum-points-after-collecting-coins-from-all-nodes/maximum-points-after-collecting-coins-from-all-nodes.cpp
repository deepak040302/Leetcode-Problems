class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int node,int par,int flg,vector<vector<int>>&adj, vector<int>& coins, int k){
        if(flg>14) return 0;
        if(dp[node][flg]!=-1) return dp[node][flg];

        int val  = coins[node]/(pow(2,flg));
        int a = val - k;
        int b = floor(val/2.0);

        for(auto i : adj[node]){
            if(par!=i){
                a += dfs(i,node,flg,adj,coins,k);
                b += dfs(i,node,flg+1,adj,coins,k);
            } 
        }
        return dp[node][flg]=max(a,b);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=coins.size();
        dp.resize(n,vector<int>(15,-1));
        vector<vector<int>>adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }        
        return dfs(0,-1,0,adj,coins,k);

    }
};
