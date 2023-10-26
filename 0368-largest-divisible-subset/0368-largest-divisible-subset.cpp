class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int len = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<pair<int,int>>dp(len);
        
        int startIndex = 0;
        
        int maxSubset = 0;
        
        dp[0] = {1,-1};
        
        for(int index = 1; index < len; index++){
            
            dp[index] = {1, -1};
            
            for(int j = 0;  j < index; j++){
                
                if((nums[index] % nums[j] == 0) || (nums[j] % nums[index] == 0)){
                    
                    int currLen = dp[index].first;
                    
                    if(currLen < (1 + dp[j].first)){
                        
                        dp[index] = {(1 + dp[j].first), j};
                    }
                }
            }
            
            
            if(maxSubset < dp[index].first){
                
                maxSubset = dp[index].first;
                startIndex = index;
            }
            
        }
        
        
        vector<int>divisibleSubset;
        
        divisibleSubset.push_back(nums[startIndex]);
        
  
        
        while(dp[startIndex].second != -1){
   
            divisibleSubset.push_back(nums[dp[startIndex].second]);
            
            startIndex = dp[startIndex].second;
        }
        
        reverse(divisibleSubset.begin(), divisibleSubset.end());
        
        return divisibleSubset;
    }
};