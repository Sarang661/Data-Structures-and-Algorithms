class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = s.size();
        
        int start = 0;
        
        map<char,int>position;
        
        int ans = 0;
        
        for(int curr = 0; curr < len; curr++){
            
            if(position.find(s[curr])!= position.end()){
                start = max( start, position[s[curr]]+1);
            }
            
            position[s[curr]] = curr;
            ans = max(ans, curr-start+1);
          
        }
        
        
        return ans;
    }
};