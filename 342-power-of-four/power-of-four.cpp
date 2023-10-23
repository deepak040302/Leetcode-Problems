class Solution {
public:
    bool isPowerOfFour(int n) {
        int ct=0;
        int a=n;

        while(a){
            a=a/2;
            ct+=1;
        }

        if(ct&1){
            return n!=0 and (n&(n-1))==0;
        }

        return 0;
    }

    // 00001110
    // 00001111
};