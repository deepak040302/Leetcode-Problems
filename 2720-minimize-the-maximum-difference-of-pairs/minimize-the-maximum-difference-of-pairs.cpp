class Solution {
public:
    bool solve(vector<int>&nums,int p,int mid){
        int ct=0;
        for(int i=1 ; i<nums.size();i++){
            if(nums[i] - nums[i-1] <= mid){ ct+=1; i+=1; }
        }
        return ct>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int s=0,e = nums.back();
        int ans=1e9;
        while(s<=e){
            int mid = (s+e)/2;
            if(solve(nums,p,mid)){
                ans=min(ans,mid);
                e = mid - 1;
            }else s = mid + 1;
        }

        return ans;
    }
};