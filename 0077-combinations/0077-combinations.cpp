class Solution {
    
private:
    
    void findAllCombinations(int n, int curr, vector<vector<int>>&ans, vector<int>&temp, int k){
        
         if(k == 0){
      
            ans.push_back(temp);
            return;
        }
        
        
        if(curr > n){
            
            return;
        }
        
        temp.push_back(curr);
        
        findAllCombinations(n, curr+1, ans, temp, k-1);
        
        temp.pop_back();
        
        findAllCombinations(n, curr+1, ans, temp, k);
        
    }
    
    
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        
        findAllCombinations(n, 1, ans, temp, k);
        
        return ans;
    }
};