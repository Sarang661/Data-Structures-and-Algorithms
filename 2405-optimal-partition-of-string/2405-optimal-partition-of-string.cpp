class Solution {
public:
    int partitionString(string s) {
        
        vector<int>freq(26,0);
        int ans = 1;
        
        for(int index = 0; index < s.size(); index++){
            
         
            if(freq[s[index]-'a']>0){
                ans++;
                fill(freq.begin(), freq.end(), 0);
                 freq[s[index]-'a']++;
            }
            else{
                freq[s[index]-'a']++;
            }
        }
        
        return ans;
    }
};