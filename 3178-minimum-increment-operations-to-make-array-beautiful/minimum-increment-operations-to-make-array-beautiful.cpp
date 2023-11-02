class Solution {
public:
    int n;
    vector<long long>dp;
    long long solve(int i,vector<int>&nums,int k){
        if(i > n-3) return 0;
        if(dp[i]!=-1) return dp[i];
        long long a = max(0,k-nums[i]) + solve(i+1,nums,k);
        long long b = max(0,k-nums[i+1]) + solve(i+2,nums,k);
        long long c = max(0,k-nums[i+2]) + solve(i+3,nums,k);
        return dp[i]=min(a,min(b,c));
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        n=nums.size();
        dp.resize(n,-1);
        return solve(0,nums,k);

    }
};