class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i>=nums1.size() || j>=nums2.size()) return -1e8;
        if(dp[i][j]!=-1) return dp[i][j];

        int a=-1e8,b=-1e8,c=-1e8;

        a = nums1[i]*nums2[j] + max(0,solve(i+1,j+1,nums1,nums2));
        b = solve(i+1,j,nums1,nums2);
        c = solve(i,j+1,nums1,nums2);
    
        return dp[i][j]=max(a,max(b,c));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return solve(0,0,nums1,nums2);
    }
};