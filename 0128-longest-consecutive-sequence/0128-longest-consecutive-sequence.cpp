class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>ele;
        
        int ans = 0;
        
        for(auto num:nums){
            
            ele.insert(num);
        }
        
        for(auto num: nums){
            
            if(ele.find(num-1)==ele.end()){
                
                int currLen = 1;
                int currNum = num+1;
                
                while(ele.find(currNum) != ele.end()){
                    
                    currNum++;
                    currLen++;
                }
                
                ans = max(ans, currLen);
            }
        }
        
        
        return ans;
    }
};