class Solution {
public:
    int bfs(vector<vector<int>>&routes,unordered_map<int,vector<int>>&adj,int source, int target){
        unordered_set<int>vis;
        int ct=0;
        queue<vector<int>>q;
        q.push({source,ct});
        vis.insert(source);
        
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            // cout<<f[0]<<" "<<f[1]<<"\n";
            
            if(f[0]==target) return f[1];
            
            for(auto i : adj[f[0]]){
                for(auto j : routes[i]){
                    if(vis.find(j)==vis.end()){
                        vis.insert(j);
                        q.push({j,f[1]+1});
                    }
                }
                routes[i].clear();
            }

        }
        return -1;
    }


    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>adj;
        int ct=1;

        for(int i=0;i<routes.size();i++){
            for(auto j : routes[i]){
                adj[j].push_back(i);
            }
        }

        
        return bfs(routes,adj,source,target);
    }
};
