class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>dp(n);
        dp[n-1] = 0;

        for(int index = n-2; index >= 0; index--){
            
                     
            dp[index] = n;
        
            for(int j= 1; j <= nums[index]; j++){
            
                int curr = min(n-1, index+j);
                
                dp[index] = min(dp[index], dp[curr]+1);

              
            }          
        }
        
        return dp[0];
    }
};