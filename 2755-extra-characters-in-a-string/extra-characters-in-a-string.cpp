class Solution {
public:
    vector<int>dp;
    int solve(int i,string s,unordered_set<string>&dict){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int sum=1e8 , a = 1e8;
        
        a = 1 + solve(i+1,s,dict);
        
        string ss;
        for(int j=i;j<s.size();j++){
            ss.push_back(s[j]);
            if(dict.count(ss)) sum = min(sum,solve(j+1,s,dict));
        }

        return dp[i]=min(sum,a);
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        dp.resize(s.size()+1,-1);
        unordered_set<string>dict(dictionary.begin(),dictionary.end());
        return solve(0,s,dict);
    }
};