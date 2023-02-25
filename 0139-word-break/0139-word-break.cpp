class Solution {
private:
    
    bool findIfPossible(string &s, vector<int>&dp, set<string>&st, int index){
        
        if(index == s.size()){
            return 1;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        dp[index] = 0;
        
        for(int i = index; i < s.size(); i++){
            
            if(st.find(s.substr(index,i-index+1))!=st.end()){
                
                dp[index] = max(dp[index], (int)findIfPossible(s, dp, st, i+1));
            }
        }
                                   
      return dp[index];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int len = s.size();
        
        vector<int>dp(len,-1);
        
        set<string>st;
        
        for(int index = 0; index < wordDict.size(); index++){
            st.insert(wordDict[index]);
        }
        
      return  findIfPossible(s, dp, st, 0);
            
        
    }
};