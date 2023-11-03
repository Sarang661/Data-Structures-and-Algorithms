class Solution {
    
private:
    
    int minCount(vector<vector<int>>&dp, vector<int>&coins, int amount, int index){
        
        
      if(index==0){
           if(amount%coins[index]==0){
               return amount/coins[index];
           }
           else{
               return 1e9;
           }
       }
        
        if(dp[index][amount] != -1){
            
            return dp[index][amount];
        }
        int take = 1e9;
        
        if(amount >= coins[index]){
            
            take = 1 + minCount(dp, coins, amount-coins[index], index);
            
        }
        
        int notTake = -1;
        
        notTake = minCount(dp, coins, amount, index-1);
        
        
        return dp[index][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        
     int minimumCoins =  minCount(dp, coins, amount, coins.size()-1);
        
        if(minimumCoins == 1e9){
            
            return -1;
        }
        
        return minimumCoins;
    }
};