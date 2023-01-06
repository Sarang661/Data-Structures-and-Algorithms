class Solution {
    
private:
    
    void findAllCombinations(int &n, int &k, int sum, vector<int>&currCombination,  vector<vector<int>>&ans, int currNum, int val){
        
        if(currNum == k || val > 9){
            
            // cout<<sum<<" "<<currNum<<"\n";
            
              if(sum == n && currNum == k){
                ans.push_back(currCombination);
            }
            return;
            
        }
        
         currCombination.push_back(val);
        
        int num = val;
        
        findAllCombinations(n, k, sum+val, currCombination, ans, currNum+1, num+1);
        
        currCombination.pop_back();
        
        findAllCombinations(n, k, sum, currCombination, ans, currNum, num+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        int sum = 0;
        vector<int>currCombination;
        
        findAllCombinations(n, k, sum, currCombination, ans, 0, 1);
        
        return ans;
    }
};