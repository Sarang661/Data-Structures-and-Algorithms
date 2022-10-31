class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int Row = rows-1;
        int Col = 0;
        
      
        for(int i=rows-1;i>=0;i--){
            int currRow = i;
            int currCol = 0;
            int ele = matrix[currRow][currCol];
            while(currRow<=(rows-1)  && currCol<=(cols-1)){
                if(ele!=matrix[currRow][currCol]){
                  return false;
                }
                  currRow++;
                    currCol++;
            }
        }
        
                for(int i=1;i<cols;i++){
            int currRow = 0;
            int currCol = i;
            int ele = matrix[currRow][currCol];
            while(currRow<=(rows-1) && currCol<=(cols-1)){
                if(ele!=matrix[currRow][currCol]){
                  return false;
                }
                  currRow++;
                    currCol++;
            }
        }
        
        return true;
    }
};