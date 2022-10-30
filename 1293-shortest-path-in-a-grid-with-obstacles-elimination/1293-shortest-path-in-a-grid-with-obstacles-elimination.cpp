
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(rows==1 && cols==1){
            return 0;
        }
        vector<vector<int>>visited(rows,vector<int>(cols,-1));
        queue<vector<int>>currState;
        
        int minPath = INT_MAX;
        
        currState.push({0,0,0,k});
        while(currState.empty() == false){
            vector<int>curr = currState.front();
             currState.pop();
            int x = curr[0];
            int y = curr[1];
            int pathLen = curr[2];
            int remain = curr[3];
           
                
                if(x<0 || y<0 || x>=rows || y>=cols){
                    continue;
                }
             if(x==(rows-1) && y==(cols-1)){
                        return pathLen;
                    }
                   
              if(grid[x][y] == 1){
                       if(remain>0){
                           remain--;
                       }
                  else{
                      continue;
                  }
                    }
             if((visited[x][y]!= -1 && visited[x][y]>= remain)){
                        continue;
                    }
                    visited[x][y] =  remain;
                  
                   
                    currState.push({x+1,y,pathLen+1,remain});
                    currState.push({x-1,y,pathLen+1,remain});
                    currState.push({x,y-1,pathLen+1,remain});
                    currState.push({x,y+1,pathLen+1,remain});
                
            
        }
        return -1;
    }
};