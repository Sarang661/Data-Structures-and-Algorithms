class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] < target){
                ans = mid + 1;
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid -1;
            }
        }
        
        return ans;
    }
};