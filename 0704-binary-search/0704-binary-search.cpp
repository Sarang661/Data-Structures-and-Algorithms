class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int ans = -1;
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[mid] > target){
                high = mid-1;
            }
            
            if(nums[mid] < target){
                
               low = mid+1;
            }
        }
        
        return ans;
    }
};