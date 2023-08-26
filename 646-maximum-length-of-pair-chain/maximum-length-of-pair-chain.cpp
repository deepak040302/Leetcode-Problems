class Solution {
private:
    int solve(int i,int prev,vector<vector<int>>&pairs,vector<vector<int>>&dp){
        if(i==pairs.size()) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int not_pick= 0 + solve(i+1,prev,pairs,dp);
        int pick = INT_MIN;
        if(prev==-1 or pairs[i][0]>pairs[prev][1]) pick = 1+solve(i+1,i,pairs,dp);
        
        return dp[i][prev+1]=max(pick,not_pick);
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>>dp(pairs.size()+1,vector<int>(pairs.size()+1,-1));
        sort(pairs.begin(),pairs.end());
        return solve(0,-1,pairs,dp);
    }
};