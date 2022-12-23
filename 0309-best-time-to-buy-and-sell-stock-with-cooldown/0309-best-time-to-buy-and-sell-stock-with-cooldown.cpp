class Solution {

    private:
    
    int find(vector<int>&prices, vector<vector<int>>&dp, int index, int n,int j){
        if(index>=n){
            return 0;
        }
        
      
        if(dp[index][j]!= -1){
            
            return dp[index][j];
        }
        
        if(j){
            
            return dp[index][j] = max(-prices[index] + find(prices,dp,index+1,n,0),  find(prices,dp,index+1,n,1));
        }
        else{
            
              return dp[index][j] = max(prices[index] + find(prices,dp,index+2,n,1),  find(prices,dp,index+1,n,0));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        
        // dp[0][0];
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
       return  find(prices, dp, 0, n, 1);
        
    }
};