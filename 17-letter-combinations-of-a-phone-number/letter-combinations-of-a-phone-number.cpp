class Solution {
public:
    vector<string>ans;

    void solve(int i,vector<string>&mp,string digits,string& s){
        if(i==digits.size()) {
            if(s.size()>0) ans.push_back(s);
            return;
        }

        string ss = mp[(digits[i]-'0')-1];
        for(auto k : ss){
            s.push_back(k);
            solve(i+1,mp,digits,s);
            s.pop_back();    
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mp ={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s="";
        solve(0,mp,digits,s);
        return ans;

    }
};