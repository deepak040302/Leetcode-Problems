class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>>& mat){
        int n = mat.size(),m=mat[0].size();

        vector<vector<int>>ans=mat;
        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<vector<int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int i = q.front()[0];
            int j = q.front()[1];
            int d = q.front()[2];
            q.pop();
            ans[i][j]=d;
            
            if(i-1>=0 and i-1<n and j>=0 and j<m and mat[i-1][j]==1 and vis[i-1][j]==0){
                vis[i-1][j]=1;
                q.push({i-1,j,d+1});
            }

            if(i+1>=0 and i+1<n and j>=0 and j<m and mat[i+1][j]==1 and vis[i+1][j]==0){
                vis[i+1][j]=1;
                q.push({i+1,j,d+1});
            }

            if(i>=0 and i<n and j-1>=0 and j-1<m and mat[i][j-1]==1 and vis[i][j-1]==0){
                vis[i][j-1]=1;
                q.push({i,j-1,d+1});
            }

            if(i>=0 and i<n and j+1>=0 and j+1<m and mat[i][j+1]==1 and vis[i][j+1]==0){
                vis[i][j+1]=1;
                q.push({i,j+1,d+1});
            }
        }

        return ans;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return bfs(mat);
    }
};