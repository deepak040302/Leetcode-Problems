class Solution {
public:

    unordered_set<char>s={'A','E','I','O','U','a','e','i','o','u'};
    
    bool valid(char c){
        return s.count(c);
    }

    string sortVowels(string s) {
        vector<int>v;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(valid(s[i])) v.push_back(s[i]);
        }    
        
        sort(v.begin(),v.end());
        
        int k=0;
        for(int i=0;i<n;i++){
            if(valid(s[i])) s[i]=v[k++]; 
        }

        return s;
    }
};