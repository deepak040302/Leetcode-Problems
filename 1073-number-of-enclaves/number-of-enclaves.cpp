class Solution {
public:
    bool isvalid(int nr, int nc ,int n, int m)
    {
        return nr>=0 && nc>=0 && nr<n && nc<m; 
    }
    void dfs(int r , int c,vector<vector<int>>&grid , vector<vector<int>>&vis , int n,int m,int dr[],int dc[])
    {
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isvalid(nr,nc,n,m) && !vis[nr][nc] && grid[nr][nc]==1)
              dfs(nr,nc,grid,vis,n,m,dr,dc);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1)
                  dfs(i,j,grid,vis,n,m,dr,dc);
             }
         }
         
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(!vis[i][j] && grid[i][j]==1)
                  cnt++;
             }
         }
         return cnt;
    }
};