class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])){
                mp[s[i]].first+=1;
                mp[s[i]].second=i;
            }else{
                mp[s[i]]={1,i};
            }
        }

        unordered_set<char>st;

        int ans=0;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])) continue;
            int lst = mp[s[i]].second;
            if(lst==i) continue;
            int cnt=0;
            if(mp[s[i]].first>2) cnt=1;
            unordered_set<char>srt;
            for(int k=i+1;k<lst;k++) srt.insert(s[k]);
            ans+=srt.size();
            st.insert(s[i]);
        }

        return ans;

    }
};