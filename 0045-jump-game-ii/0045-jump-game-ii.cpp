class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>dp(n, 1e9);
        
        dp[n-1] = 0;
        
        for(int index = n-2; index >= 0; index--){
            
            for(int jump = 0; jump <= nums[index]; jump++){
                
                if(index+jump < n){
                 
                dp[index] = min(1+dp[index+jump], dp[index]);
                    
                    }
            }
        }
        
     
        
        return dp[0];
    }
};