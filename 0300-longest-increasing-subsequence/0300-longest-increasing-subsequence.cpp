class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int len = nums.size();
        
        int lis = 1;
        
        vector<int>dp(len, -1);
        
        dp[0] = 1;
        
        for(int index = 1; index < nums.size(); index++){
            
            dp[index] = 1;
            
            for(int j = 0; j < index; j++){
                
                if(nums[index] > nums[j]){
                    
                    dp[index] = max(dp[index], 1 + dp[j]);
                }
            }
            
            lis = max(lis, dp[index]);
        }
        
        return lis;
    }
};