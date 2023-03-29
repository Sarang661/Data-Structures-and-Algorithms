class Solution {
    
    int find(vector<int>&s, int prev, vector<vector<int>>&dp, int n, int index){
        
        if(index == n){
            return 0;
        }
        
        if(dp[index][prev]!= -1){
            return dp[index][prev];
        }
        int val1 = (prev+1)*s[index] + find(s, prev+1, dp, n, index+1);
        
        int val2 = find(s, prev, dp, n, index+1);
        
        return dp[index][prev] = max(val1, val2);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        sort( satisfaction.begin(),  satisfaction.end());
       vector<vector<int>>dp(n, vector<int>(n+1,-1));
        
        return find(satisfaction, 0, dp, n, 0);
    }
};