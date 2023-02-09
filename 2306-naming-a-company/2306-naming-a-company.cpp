#define ll long long int
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        ll len = ideas.size();
        
        vector<vector<ll>>val(26,vector<ll>(26,0));
        
        ll ans = 0;
        
        unordered_set<string>st;
        
        for(int i=0;i<len;i++){
            st.insert(ideas[i]);
        }
        
        for(int i=0;i<len;i++){
            string s = ideas[i];
            char c = s[0];
            
            for(int j ='a'; j<='z';j++){
                s[0] = (char)j;
                
                if(st.find(s)==st.end()){
                
                    
                    val[c-'a'][j-'a']++;
                }
            }
        }
        
        // aba  cba  chd  chf ghj
      
        for(int i=0; i<len; i++){
             string s = ideas[i];
            char c = s[0];
            for(int j ='a'; j<='z';j++){
                s[0] = j;
    
                if(st.find(s)==st.end()){
       
                    ans += val[j-'a'][c-'a'];
                }
            }
        }
        
        return ans;
    }
};