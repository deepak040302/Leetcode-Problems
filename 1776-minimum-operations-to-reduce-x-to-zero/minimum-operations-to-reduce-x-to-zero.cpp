class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(auto i : nums) sum+=i;
        int tar = sum-x;
        int i=0,j=0,n = nums.size(),ans=1e9;;
        sum=0;
        if(tar<0) return -1;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum<tar){
                j+=1;
            }else{
                while(sum>tar){
                    sum-=nums[i];
                    i+=1;
                }
                if(sum==tar){
                    cout<<i<<" "<<j<<endl;
                    ans=min(ans,n-(j-i+1));
                }
                j+=1;
            }
        }
        return ans==1e9?-1:ans;
    }   
};