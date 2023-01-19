class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int currMin = nums[0];
        int currMax = nums[0];
        int totalSum = nums[0];
        int len = nums.size();
        
        for(int index = 1; index < len; index++){
            
            currMin = min(nums[index], currMin + nums[index]);
            mini = min(mini, currMin);
            currMax = max(nums[index], currMax + nums[index]);
            maxi = max(maxi, currMax);
            totalSum += nums[index];
        }
        
        
        // cout<<mini<<" "<<maxi<<"\n";
        
        if(maxi<0){
            return maxi;
        }
        return max(totalSum-mini, maxi);
    }
};