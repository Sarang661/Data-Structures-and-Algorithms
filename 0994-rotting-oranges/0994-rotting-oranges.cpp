class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        int numRows = grid.size();
        int numCols = grid[0].size();
        int fresh = 0;
        
        queue<pair<int,int>>rotten;
        
        for(int index = 0; index < numRows; index++){
            
            for(int j = 0; j < numCols; j++){
                
                if(grid[index][j] == 2){
                    
                    rotten.push({index, j});
                }
                
                  if(grid[index][j] == 1){
                    
                    fresh++;
                }
            }
        }
                 int currNum = 1;
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        
        int mins = 0;
        bool flag = false;
        

        while(!rotten.empty()){
            
           flag = false;
            int size =  rotten.size();

            for(int curr = 0; curr < size; curr++){
                
                if(!flag){
                      cout<<size<<"\n";
                }
              
                  int x1 = rotten.front().first;
                  int y1 = rotten.front().second;
                  rotten.pop();
                
    
                 for(int index = 0; index < 4; index++){
                
             
                        int currX = x[index] + x1;
                        int currY = y[index] + y1;
                    
                     if((currX>= 0) && (currX < numRows) && (currY >=0) && (currY < numCols)){
                         
                               
                         if(grid[currX][currY] ==  1){
                    
                            
                            flag = true;
                             fresh--;
                         
                            rotten.push({currX, currY});
                            grid[currX][currY] = 2;
                         }
                     }
                   }
            }
            
         
                    if(flag){
                       mins++;
                }
            
            currNum++;
          
      
        }
        
        if(fresh > 0){
            
            return -1;
        }
        
        return mins;
    }
};