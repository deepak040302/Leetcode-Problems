class Solution {
public:
    string longestPalindrome(string ss) {
        int strt=0,max=1;
        int n = ss.size();

        for(int i=1;i<n;i++){
            int s=i,e=i;

            while(s>=0 && e<n && ss[s]==ss[e]){
                int len = e-s+1;
                if(len>max){
                    max = len;
                    strt = s;
                }
                s-=1;
                e+=1;
            }
            
            s=i-1,e=i;

            while(s>=0 && e<n && ss[s]==ss[e]){
                int len = e-s+1;
                if(len>max){
                    max = len;
                    strt = s;
                }
                s-=1;
                e+=1;
            }
        }
        return ss.substr(strt,max);
    }
};

