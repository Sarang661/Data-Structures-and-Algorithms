class Solution {
    
private:
    
    int findMinOperations(string &word1, string &word2, vector<vector<int>>&dp, int index1, int index2){
        
        if(index1 == word1.size()){
            
            return word2.size() - index2;
        }
        
        if(index2 == word2.size()){
            
            return word1.size() - index1;
        }
        
        if(word1[index1] == word2[index2]){
            
            return dp[index1][index2] = findMinOperations(word1, word2, dp, index1+1, index2 +1);
        }
        
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        
        int minVal = min({findMinOperations(word1, word2, dp, index1+1, index2+1), findMinOperations(word1, word2, dp, index1+1, index2), findMinOperations(word1, word2, dp, index1, index2+1)});
            
            
        return dp[index1][index2] = 1 + minVal;
    }
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return findMinOperations(word1, word2, dp, 0, 0);
    }
};