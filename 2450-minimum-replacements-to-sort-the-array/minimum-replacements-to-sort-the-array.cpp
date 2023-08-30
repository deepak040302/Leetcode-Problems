class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n = nums.size();
        int min=nums[n-1];


        for(int i=n-2;i>=0;i--){
            int dvd = ceil(nums[i]/(min*1.0));
            
            ans+=dvd-1;

            min = nums[i]/dvd;
        }

        return ans;
    }
};