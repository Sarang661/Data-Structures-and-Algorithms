class Solution {
private:
    int findMaxRobbery(vector<int>&nums, int index, vector<int>&dp){
        
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        
        int weWillRob = nums[index] + findMaxRobbery(nums,index+2,dp);
        int weWillNotRob = findMaxRobbery( nums, index+1,dp);
        
        return dp[index] = max(weWillRob, weWillNotRob);
    }
public:
    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size(), -1);
        
        return findMaxRobbery(nums, 0, dp);
    }
};