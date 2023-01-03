class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int len = strs.size();
        int col = strs[0].size();
        
       
        int numCols = 0;
   
        
        for(int index = 0; index < col; index++){
            
      
            
            for(int j = 1; j < len; j++){
                
                if(strs[j-1][index] > strs[j][index]){

                    numCols++;
                    break;
                }
               
            }
            
         
        }
        
        return numCols;
        
    }
};