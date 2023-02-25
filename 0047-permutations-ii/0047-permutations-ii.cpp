class Solution {
    
private:
    
    void findAllUniquePermutations(vector<int>&nums, int index, set<vector<int>>&st){
        
        if(index == nums.size()){
            st.insert(nums);
            return;
        }
        
       
        for(int j = index; j < nums.size(); j++){
            
            if(j == index || nums[j] != nums[index]){
                
                swap(nums[j], nums[index]);
                findAllUniquePermutations(nums, index+1, st);
                swap(nums[j], nums[index]);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        set<vector<int>>st;
        findAllUniquePermutations(nums, 0,  st);
        
        for(auto x:st){
            ans.push_back(x);
        }
        
        return ans;
    }
};