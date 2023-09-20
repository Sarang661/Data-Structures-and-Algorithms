class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        map<int,int>prefix;
        
        int totalSum = 0;
       for(int index = 0; index < nums.size(); index++){
           
           totalSum+=nums[index];
       }
        
        int requiredSum = totalSum - x;
 

        int ans = -1;
        
        prefix[0] = -1;
        
         int currSum = 0;
        
        for(int index = 0; index < nums.size(); index++){
            
           currSum+=nums[index];
            
            
             if((prefix.find(currSum) == prefix.end())){
                
                prefix[currSum] = index;
            } 
            
            if(prefix.find(currSum-requiredSum) != prefix.end()){
                
                 
                ans = max(ans, index - prefix[currSum-requiredSum]);
            }
            
           
            
        }
        
        
        if(ans == -1){
            
            return -1;
        }
        return nums.size() - ans;
    }
};