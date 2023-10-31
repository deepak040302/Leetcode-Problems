class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int pre=pref[0];
        int pre1=0;
        for(int i=1;i<pref.size();i++){
            pre1=pre^pref[i];
            pref[i]=pre1;
            pre=pre^pre1;
        }
        return pref;
    }


    // x=y^a
};