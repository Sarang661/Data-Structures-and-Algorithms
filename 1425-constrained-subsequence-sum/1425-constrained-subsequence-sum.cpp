class Solution {
public:
    
   
    
    
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        
        int len = nums.size();
        
      vector<int>dp(len, 0);
        
        priority_queue<pair<int,int>>q;
        
      dp[0] = nums[0];
        q.push({nums[0], 0});
         int maxi = dp[0];
        
        for(int index = 1; index < len; index++){
            
            int curr= nums[index];
            
            while(!q.empty()){
                
                int currIndex = q.top().second;
                
                if((index - currIndex)>k){
                    q.pop();
                    continue;
                }
                
                curr = max(curr, curr + q.top().first);
                break;
            }
            
            dp[index] = curr;
            q.push({curr, index});
            maxi = max(maxi, dp[index]);
        }
        
        
        return maxi;
    }
};