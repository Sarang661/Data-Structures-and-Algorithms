class Solution {

private:
    
    void findAllSubsequences(  set<vector<int>>&st,vector<int>&nums, int n, vector<int>&curr, int index){
        
        if(index == n){
            
            if(curr.size() > 1){
              st.insert(curr);
            }
            
            return;
        }
        
        if(curr.size() == 0 || curr.back()<=nums[index]){
            
            curr.push_back(nums[index]);
            findAllSubsequences(st,nums, n, curr, index+1);
            
            curr.pop_back();
        }
        
        
        findAllSubsequences(st,nums, n, curr, index+1);
        
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>curr;
        set<vector<int>>st;
        
        findAllSubsequences(st,nums, n, curr, 0);
        
        
        for(auto x:st){
            ans.push_back(x) ;        
            
        }   
        return ans;
    }
};