class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        int ans=0;
        for(auto i : roads) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        set<vector<int>>st;
        for(auto i : roads) st.insert(i);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int nn = adj[i].size()+adj[j].size();
                if(!st.count({i,j}) and !st.count({j,i})) ans=max(ans,nn);
                else ans=max(ans,nn-1);
            }
        }

        return ans;
    }
};
