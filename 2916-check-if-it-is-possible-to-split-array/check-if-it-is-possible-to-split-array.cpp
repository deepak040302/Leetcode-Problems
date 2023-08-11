class Solution1 {
public:
    vector<vector<int>>dp;
    bool solve(int i,int j,vector<int>&nums,int m){
        if(i>j) return false;
        if(j-i+1==2) return true;
        if(dp[i][j]!=-1) return dp[i][j];

        int sum=0;
        for(int k=i;k<=j;k++) sum+=nums[k];

        int a = false, b= false;
        if(sum-nums[i] >= m){
            a = solve(i+1,j,nums,m);
        }
        if(sum-nums[j] >= m){
            b = solve(i,j-1,nums,m);
        }

        return dp[i][j] = a or b;
    }

    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        dp.resize(n,vector<int>(n,-1));
        if(n==1 or n==2) return true;
        return solve(0,n-1,nums,m);
    }
};

class Solution{
public:

    bool canSplitArray(vector<int>& nums, int m) {
        int n=nums.size();
        if(n==1 or n==2) return true;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1] >= m) return true;
        }

        return false;
    }
};


// 2 3 3 2 3
// 3 3 2 3
// 3 2 3


// 1 5 6 // 