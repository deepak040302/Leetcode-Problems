class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>dp;
    int solve(int n,char c,vector<char>&nums){
        if(n==0) return 1;
        if(dp[n][c]!=-1) return dp[n][c];
        long long int ct=0;
        for(auto k : nums){
            if(c=='z'){
                ct += solve(n-1,k,nums)%mod;
            }else if(c=='a'){   
                if(k=='e') ct+=solve(n-1,k,nums)%mod;
            }else if(c=='e'){
                if(k=='a' or k=='i') ct+=solve(n-1,k,nums)%mod;
            }else if(c=='i'){
                if(k!='i') ct+=solve(n-1,k,nums)%mod;
            }else if(c=='o'){
                if(k=='u' or k=='i') ct+=solve(n-1,k,nums)%mod;
            }else if(c=='u'){
                if(k=='a') ct+=solve(n-1,k,nums)%mod;
            }
        }
        return dp[n][c]=ct%mod;

    }
    int countVowelPermutation(int n) {
        vector<char>v={'a','e','i','o','u'};
        dp.resize(n+1,vector<int>(130,-1));
        return solve(n,'z',v);
    }
};