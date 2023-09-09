class Solution {
public:

    vector<vector<int>>dp;

    int solve(int idx,int target, vector<int>&arr)
    {
        if(target==0){
            return 1;
        }

        if(idx==arr.size()){
            int n=arr.size();
            return target%arr[n-1]==0 ? 1 : 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int ct=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=target){
                ct+=solve(i,target-arr[i],arr);
            }
        }
        return dp[idx][target]=ct;
    }


    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(nums.size()+1,vector<int>(target+1,-1));
        return solve(0,target,nums);
    }
};