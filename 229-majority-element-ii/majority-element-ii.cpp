class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=0,ct1=0,ele2=0,ct2=0;

        for(auto i : nums){
            if(ele1==i){
                ct1++;
            }else if(ele2==i){
                ct2++;
            }else if(ct1==0){
                ele1=i;
                ct1+=1;
            }else if(ct2==0){
                ele2=i;
                ct2+=1;
            }else{
                ct1-=1;
                ct2-=1;
            }
        }


        vector<int>ans; 
        int k = nums.size()/3;
        int a=0,b=0;
        for(auto i : nums){
            if(i==ele1){
                a+=1;
            }else if(i==ele2){
                b+=1;
            }
        }

        if(a>k) ans.push_back(ele1);
        if(b>k) ans.push_back(ele2);
        return ans;
    }
};