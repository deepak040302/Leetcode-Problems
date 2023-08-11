class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int amt,vector<int>&coins){
        if(amt==0) return 1;
        if(i==0){
            if(amt%coins[i]==0) return 1;
            return 0;
        }

        if(dp[i][amt]!=-1) return dp[i][amt];
        int a=0,b=0;
        if(coins[i] <= amt) a = solve(i,amt-coins[i],coins);
        b = solve(i-1,amt,coins);
        return dp[i][amt]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins);
    }
};