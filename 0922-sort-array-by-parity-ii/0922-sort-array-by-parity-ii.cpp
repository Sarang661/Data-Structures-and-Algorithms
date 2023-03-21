class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int start = 0;
        int end = 0;
        
        while(start<nums.size() && end < nums.size()){
            
            if(start%2 == 0 && nums[start]%2==1){
                end = start + 1;
                while(end < nums.size()){
                    if(end%2==1 && nums[end]%2==0){
                        break;
                    }
                    end++;
                }
                swap(nums[start], nums[end]);
            }
            else if(start%2 == 1 && nums[start]%2==0){
                end = start + 1;
                 while(end < nums.size()){
                    if(end%2==0 && nums[end]%2==1){
                        break;
                    }
                    end++;
                }
                swap(nums[start], nums[end]);
            }
            start++;
        }
        
        return nums;
    }
};