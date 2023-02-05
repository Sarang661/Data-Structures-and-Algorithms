class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
       vector<int>v1(26,0);
        vector<int>v2(26,0);
        vector<int>ans;
        
        if(p.size() > s.size()){
            return ans;
        }
        
        for(int i=0;i<p.size();i++){
            v1[p[i]-'a']++;
        }
        int j=0;
        int i=0;
        
        while(j<p.size()){
            v2[s[j]-'a']++;
            j++;
        }
        if(v1==v2){
            ans.push_back(i);
        }
        while(j<s.size()){
            v2[s[i]-'a']--;
            v2[s[j]-'a']++;
            i++;
            j++;
             if(v1==v2){
            ans.push_back(i);
        }
        }
        
        return ans;
    }
};