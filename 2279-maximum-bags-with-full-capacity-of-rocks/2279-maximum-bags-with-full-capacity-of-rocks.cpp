class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        priority_queue<int, vector<int>, greater<int>>minRocks;
        
        int len = capacity.size();
        
        int currRocks = additionalRocks;
        
        int totalFullBags = 0;
        
        for(int index = 0; index < len; index++){
            
            int diff = capacity[index] - rocks[index];
            
            if(diff == 0){
                totalFullBags++;
                continue;
            }
             
            minRocks.push(diff);
        }
        
    
        
        while(currRocks>0 && !minRocks.empty()){
            
            int diff = minRocks.top();
       
            if(diff<=currRocks){
          
                currRocks = currRocks - diff;
                totalFullBags++;
                
            }
            
            else{
                
                break;
            }
            
            minRocks.pop();
            
        }
        
        return totalFullBags;
    }
};