class Solution {
private:
    
    int findLongestCommonSubsequence(string &text1, string &text2, vector<vector<int>>&dp, int i, int j){
        if(i<0 || j<0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            
            return dp[i][j];
        }
        
        if(text1[i] == text2[j]){
            
            return dp[i][j] = 1 + findLongestCommonSubsequence(text1, text2, dp, i-1, j-1);
        }
        else{
            
            return dp[i][j] = max(findLongestCommonSubsequence(text1, text2, dp, i-1, j),  findLongestCommonSubsequence(text1, text2, dp, i, j-1));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int len1 = text1.size();
        int len2 = text2.size();
        
        vector<vector<int>>dp(len1,vector<int>(len2,-1));
        
        return findLongestCommonSubsequence(text1, text2, dp, len1-1, len2-1);
    }
};