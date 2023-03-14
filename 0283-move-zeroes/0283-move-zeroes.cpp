class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int start = 0;
        int end = 0;
        
        while(end < nums.size()){
            
            while(start < nums.size() && nums[start] != 0){
                start++;
            }
            end = start + 1;
            
            while(end < nums.size() && nums[end] == 0){
                end++;
            }
            
            if(start < nums.size() && end < nums.size()){
                  swap(nums[start], nums[end]);
                start++;
            }
          
            
        }
    }
};