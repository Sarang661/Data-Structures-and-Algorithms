class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int>freq;
        
        int maxi = 0;
        int prev = 0;
        
        for(int index = 0; index < s.size(); index++){
            
            if(freq.find(s[index]) != freq.end()){
                
                prev = max(prev, freq[s[index]]+1);
               
              
            }
            
             freq[s[index]] = index;
            
            maxi = max(maxi, index - prev +1);
        }
        
        return maxi;
    }
};