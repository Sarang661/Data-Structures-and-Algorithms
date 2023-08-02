class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>result;
        
        findAllPermutations(0, nums, result);
       
        
        return result;
    }
    
    void findAllPermutations(int start, vector<int>&nums, vector<vector<int>>&result){
        
        if(start == nums.size()){
            
            result.push_back(nums);
            return;
        }
        
        
        for(int index = start; index < nums.size(); index++){
            
            swap(nums[start], nums[index]);
            
            findAllPermutations(start+1, nums, result);
            
            swap(nums[start], nums[index]);
        }
        
    }
};