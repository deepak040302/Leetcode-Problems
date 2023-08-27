class Solution {
public:
    unordered_map<int,int>mp;
    map<pair<int,int>,int>dp;

    bool solve(int i,int jump,vector<int>&stones){
        if(i==stones.size()-1) return true;
        if(i>=stones.size()) return false;
        if(dp.find({i,jump})!=dp.end()) return dp[{i,jump}];

        int a=0,b=0,c=0;

        int n1 = stones[i]+jump-1;
        int n2 = stones[i]+jump;
        int n3 = stones[i]+jump+1;
        
        if(mp.count(n1) and mp[n1]>i) a = solve(mp[n1],n1-stones[i],stones);
        
        if(mp.count(n2) and mp[n2]>i) b = solve(mp[n2],n2-stones[i],stones);

        if(mp.count(n3) and mp[n3]>i) c = solve(mp[n3],n3-stones[i],stones);


        return dp[{i,jump}]=a || b || c;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]!=1) return false;

        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }      

        return solve(1,1,stones);
    }
};