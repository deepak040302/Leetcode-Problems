class Solution {
public:
    map<char,int>mp;

    int minDeletions(string s) {
        for(auto i : s)mp[i]+=1;
        string s1;

        vector<pair<int,char>>v;

        for(auto i : mp){
            v.push_back({i.second,i.first});
        }

        sort(v.begin(),v.end(),greater<pair<int,char>>());
        for(auto i : v) s1.push_back(i.second);
        int ct=0;
        int prev = mp[s1[0]];
        for(int i=1;i<s1.size();i++){
            if(mp[s1[i]]>=prev){
                prev=max(0,prev-1);
                ct+=mp[s1[i]]-prev;
            }else{
                prev=mp[s1[i]];
            }
        }

        return ct;
        
        return 1;
    }
};