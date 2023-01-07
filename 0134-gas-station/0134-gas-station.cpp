class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        /*  
            gas -> [7,7, 6, 12, 5, 6, 5]
            station -> [1, 30, 1, 1, 1]
        
             prefix array -> [6, 12, 17, -1, 3, -1, 10]
        */
        
        int len = gas.size();
        
        int totalGas = 0;
        int totalCost = 0;
        
        for(int index = 0; index < len; index++){
            
            totalGas+=gas[index];
            totalCost+=cost[index];
            
        }
        
        if(totalGas<totalCost){
            
            return -1;
        }
        
        int startIndex = 0;
        int curr = 0;
        
        for(int index = 0; index < len; index++){
            
            curr+=(gas[index] - cost[index]);
            
            if(curr<0){
                
                startIndex = index+1;
                curr = 0;
            }
        }
        
        return startIndex;
     
    }
};