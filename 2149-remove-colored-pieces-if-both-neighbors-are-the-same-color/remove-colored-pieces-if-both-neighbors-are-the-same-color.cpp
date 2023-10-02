class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0;
        int ct=1;
        int i=0,n=colors.size();
        while(i<n-1){
            if(colors[i]==colors[i+1]){
                ct+=1;
            }else{
                if(colors[i]=='A'){
                    a+=max(0,ct-2);
                }else{
                    b+=max(0,ct-2);
                }
                ct=1;
            }
            i+=1;
        }
        if(colors[i]=='A'){
            a+=max(0,ct-2);
        }else{
            b+=max(0,ct-2);
        }
        //cout<<a<<b<<endl;
        return a>b;
    }
};