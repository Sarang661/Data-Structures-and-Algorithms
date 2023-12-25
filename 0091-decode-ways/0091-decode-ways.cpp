class Solution {
    
private:
    
    int decodeWays(string &s, int index, map<int,char>&mapping, vector<int>&dp){
        
      
        
        if(index >= s.size()){
            
            return 1;
        }
        
         if(dp[index] != -1){
            
            return dp[index];
        }
        
        int ans = 0;
        
        for(int curr = index; curr < s.size(); curr++){
            
            if(stoi(s.substr(index, curr-index+1)) > 26){
                break;
            }
            
            if(mapping.find(stoi(s.substr(index, curr-index+1))) != mapping.end()){
                
                string temp = s.substr(index, curr-index+1);
                
                if(temp[0] == '0'){
                    continue;
                }
                
                ans += decodeWays(s, curr+1, mapping, dp);
            }
        }
        
        
        return dp[index] = ans;
    }
public:
    int numDecodings(string s) {
        
        map<int,char>mapping;
        
        char curr = 'A';
        
        for(int index = 1; index <= 26; index++){
            
            mapping[index] = curr;
        
            curr++;
        }
        
        vector<int>dp(s.size(), -1);
        
        
        return decodeWays(s, 0, mapping, dp);
    }
};