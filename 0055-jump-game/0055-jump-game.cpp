class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int lastReachable= 0;
        int len = nums.size();
        
        for(int index = 0 ; index < len; index++){
            
            if(lastReachable<index){
                return false;
            }
            if(lastReachable<(min(len -1,  index+nums[index]))){
                
                lastReachable = min(len -1, index+nums[index]);
            }
        }
        
        return true;
    }
};