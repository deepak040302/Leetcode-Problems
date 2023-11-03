class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int start=1;
        vector<string>ans;
        for(int i=0;i<target.size();i++){
            int end = target[i];
            for(int j=start;j<end;j++){
                ans.push_back("Push");        
                ans.push_back("Pop");
            }
            ans.push_back("Push");
            start = target[i]+1;
        }
        return ans;
    }
};