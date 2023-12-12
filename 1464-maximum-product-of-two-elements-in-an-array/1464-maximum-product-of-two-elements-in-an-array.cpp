class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi1 = 0;
        int maxi2 = -1;
        
        
        for(int index = 1; index < nums.size(); index++){
            
            if(nums[index] > nums[maxi1]){
                
                 maxi2 = maxi1;
                maxi1 = index;
            }
            else if(maxi2 == -1 || nums[maxi2] < nums[index]){
                
                maxi2  = index;
            }
        }
        
        return (nums[maxi1]-1)*(nums[maxi2]-1);
    }
};