class Solution {
    
private:
    
    int findMaxProfit(vector<int>&prices, int index, vector<vector<vector<int>>>&dp, int buy, int k){
        if(k==0 || index == prices.size()){
            
            return 0;
        }
        
        if(dp[index][buy][k] != -1){
            
            return dp[index][buy][k];
        }
        
        if(buy){
            
            return dp[index][buy][k] = max(-prices[index] + findMaxProfit(prices,index+1, dp,0, k),                 findMaxProfit(prices,index+1, dp,1, k));
        }
                                           
           return dp[index][buy][k] = max(prices[index] + findMaxProfit(prices,index+1, dp,1, k-1),                 findMaxProfit(prices,index+1, dp,0, k));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        
        return findMaxProfit(prices, 0, dp, 1, k);
        
    }
};