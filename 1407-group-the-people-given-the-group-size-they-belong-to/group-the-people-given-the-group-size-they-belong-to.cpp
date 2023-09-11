class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>&nums) {
        int n = nums.size();
        map<int,queue<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push(i);
        }

        vector<vector<int>>ans;

        for(auto i : mp){
            int k = i.first;
            auto q = i.second;

            while(!q.empty()){
                int a=k;
                vector<int>v;
                while(a--){
                    v.push_back(q.front());
                    q.pop();
                }
                ans.push_back(v);
            }
        }

        return ans;


    }
};