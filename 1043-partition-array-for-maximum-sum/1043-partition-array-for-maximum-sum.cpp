class Solution {
    
private:
    
    int maxSumFromPartition(vector<int>&arr, int k, vector<int>&dp, int index){
        
        
        if(index >= arr.size()){
            
            return 0;
        }
        int  maxi = INT_MIN;
        
        
        if(dp[index] != -1){
            
            return dp[index];
            
        }
        for(int curr = index; curr < min(index+k, (int)arr.size()); curr++){
            
            maxi = max(maxi, arr[curr]);
            
            dp[index] = max(dp[index], (curr-index+1)*maxi + maxSumFromPartition(arr, k,dp, curr+1 ));
        }
        
        return dp[index];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int len = arr.size();
        
       vector<int>dp(len, -1);
        
        return maxSumFromPartition(arr, k, dp, 0);
    }
};