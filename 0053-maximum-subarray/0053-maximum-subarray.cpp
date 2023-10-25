class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxi = nums[0];
        
        int sum = 0;
        
        for(int index = 0; index < nums.size(); index++){
            
            sum += nums[index];
            
            maxi = max(maxi, sum);
            
            if(sum < 0){
                
                sum = 0;
            }

        }
        
        
        
        return maxi;
    }
};