class Solution {

    private:
    
    void findAllPaths(vector<vector<int>>& grid, int startRow, int startCol, int numCells, int &ans, int endRow, int endCol, int &totalCells){
        
        if(startRow == endRow && startCol == endCol){
            
           totalCells++;
            
            if(numCells == totalCells){
                ans++;
            }
            totalCells--;
            return;
        }
        
        if(startRow<0 || startCol < 0 || startRow>= grid.size() || startCol>=grid[0].size() || grid[startRow][startCol] == -1 || grid[startRow][startCol] == -2){
            return;
        }
        
        grid[startRow][startCol] = -2;
        
        totalCells++;
        
        findAllPaths(grid, startRow+1, startCol, numCells, ans, endRow, endCol, totalCells);
        findAllPaths(grid, startRow-1, startCol, numCells, ans, endRow, endCol, totalCells);
        findAllPaths(grid, startRow, startCol+1, numCells, ans, endRow, endCol, totalCells);
        findAllPaths(grid, startRow, startCol-1, numCells, ans, endRow, endCol, totalCells);
        
        totalCells--;
        
        grid[startRow][startCol] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
     
        
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        int startRow = 0;
        int startCol = 0;
        int endRow = 0;
        int endCol = 0;
        int ans = 0;
        int totalCells = 0;
        int numCells = 0;
        
        for(int row = 0; row < numRows; row++){
            
            for(int col = 0; col < numCols; col++){
                
                if(grid[row][col] == 1){
                    startRow = row;
                    startCol = col;
                }
                if(grid[row][col] == 2){
                 
                     endRow  = row;
                    endCol = col;
            
                }
                
                 if(grid[row][col] == 0){
                   numCells++;
                }
                
            }
        }

        numCells+=2;
        
        findAllPaths(grid, startRow, startCol, numCells, ans, endRow, endCol, totalCells);
        
        return ans;
    }
};