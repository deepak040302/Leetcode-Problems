class Graph {
public:
    int solve(int source, int dst, vector<vector<vector<int>>>&adj){
        int n = adj.size();
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>>q;
        vector<int>dis(n+1,1e9);
        q.push({0,source});

        while(!q.empty()){
            auto f =q .top();
            q.pop();
            if(f[1]==dst) return f[0];
            for(auto i : adj[f[1]]){
                int v = i[0];
                int d = i[1];

                if(f[0] + d < dis[v]){
                    dis[v] = f[0] + d;
                    q.push({f[0]+d,v});
                }
            }   
        }

        return dis[dst]==1e9?-1:dis[dst];
    }

    vector<vector<vector<int>>> adj;
    int nn=0;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        nn=n;
        for(auto i:edges) {
            adj[i[0]].push_back({i[1],i[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return solve(node1,node2,adj);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */