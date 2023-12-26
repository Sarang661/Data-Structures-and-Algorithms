class Solution {
    
private:
    
    long long mod = 1e9 + 7;
    
    int find( vector<vector<int>>&dp, int k,int n,int target){
        
      
    
         if(target == 0 && n == 0){
            return 1;
        }

        if((target == 0 && n>0) || n<=0){
            return 0;
        }
        
// cout<<dp.size();
        if(dp[n][target] != -1){
            
            return dp[n][target];
        }
        
        long long curr = 0;
      
        for(int index = 1; index <= k; index++){
            
            if(index <= target){
                   curr =  (curr + find(dp, k, n-1, target-index))%mod;
            }
          
        }
        
        return dp[n][target] = curr;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        
        
        vector<vector<int>>dp(n+1, vector<int>(target+1,-1));
        
        // cout<<dp.size()<<" "<<n<<"\n";
        return find(dp, k, n,target);
    }
};