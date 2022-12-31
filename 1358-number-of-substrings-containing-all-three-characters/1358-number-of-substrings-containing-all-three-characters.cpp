class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int start = 0;
        int end = 0;
        
        int len = s.size() -1;
        
        map<char,int>freq;
        int ans = 0;
        
        while(end <= len){
            
            freq[s[end]]++;
          
            while(start<end && freq.size()==3){
                ans++;
                ans+= (len-end);
            
                freq[s[start]]--;
                if(freq[s[start]]==0){
                    freq.erase(s[start]);
                }
                start++;
            }
            
            
            end++;
        }
        
        return ans;
    }
};