class Solution {
public:
    int mod =1e9+7;
    int countHomogenous(string s) {
        long ct=1;
        long long int ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                ans+=(((ct*(ct+1))/2)*1LL)%mod;
                ct=1;
            }else{
                ct+=1;
            }
        } 
        ans=(ans+0LL+((ct*(ct+1))/2)+0LL)%mod;
        return ans;
    }
};