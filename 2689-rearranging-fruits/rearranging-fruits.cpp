class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int n = b1.size();
        long long mn = 1e12;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[b1[i]]++;
            mp[b2[i]]--;
            mn=min(mn,1LL*min(b1[i],b2[i]));
        }
        vector<int>l2r,r2l;
        for(auto i : mp){
            if(i.second & 1) 
                return -1;
            else if(i.second>0){
                int tmp = i.second/2;
                while(tmp--)
                    l2r.push_back(i.first);
            }else if(i.second<0){
                int tmp = (i.second/2)*-1;
                while(tmp--)
                    r2l.push_back(i.first);
            }
        }


        sort(l2r.begin(),l2r.end());
        sort(r2l.begin(),r2l.end(),greater<int>());

        long long ans=0;
        // cout<<l2r.size()<<" "<<r2l.size()<<endl;;
        // int k = l2r.size();
        for(int i=0;i<l2r.size();i++){
            ans+=min(2*mn,1LL*min(l2r[i],r2l[i]));
        }

        return ans;
    }
};