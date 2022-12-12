class Solution {
public:
    int climbStairs(int n) {
        // 1 2  
        // n = 1  1  n= 2  0th or  1st   n = 3     1st 2nd  number of ways to get up to 1st step + number of ways to get u to 3rd step
        
        vector<int>dp(n+1,0);
        
        dp[0] = 1;
        
    dp[1]  = 1;
        
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        
        
        return dp[n];
    }
};