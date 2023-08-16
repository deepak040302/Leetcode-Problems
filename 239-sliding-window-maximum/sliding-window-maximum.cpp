class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<int>q,dp;
        for(int i=0;i<k;i++){
            q.push(nums[i]);
        }
        ans.push_back(q.top());

        for(int i=k;i<nums.size();i++){
            
            if(q.top()==nums[i-k]){
                q.pop();
            }else{
                dp.push(nums[i-k]);
            }

            while(!dp.empty() and dp.top() == q.top())
            {
                q.pop();
                dp.pop();
            }

            q.push(nums[i]);
            ans.push_back(q.top());



            // q.push(nums[i+k-1]);

            // ans.push_back(q.top());
        }
        return ans;
    }
};