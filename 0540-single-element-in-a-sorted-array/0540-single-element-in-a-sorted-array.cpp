class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size() - 1;
        
        int len = nums.size();
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
       
            if((mid==0 || nums[mid]!=nums[mid-1]) && (mid== len-1 || nums[mid]!=nums[mid+1])){
                return nums[mid];
            }
            else if(mid < len-1 && nums[mid]==nums[mid+1]){
                
                if(mid%2==0){
                     low = mid+1;
                }
                else{
                    high = mid - 1;
                }
               
            }
            else{
                 if((mid-1)%2==0){
                     low = mid+1;
                }
                else{
                    high = mid - 2;
                }
            }
        }
        
        return 0;
    }
};