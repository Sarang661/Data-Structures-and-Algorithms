class Solution {
    
private:
    bool bfs(vector<vector<int>>&grid, int i, int j){
        
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j] = 1;
        bool flag = true;
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
         
               if( x-1 < 0 || y-1 < 0 || x+1 >= grid.size() || y+1 >= grid[0].size()){
                flag = false;
            }
            
            if(x+1 < grid.size() && grid[x+1][y]  == 0){
                q.push({x+1, y});
                grid[x+1][y] = 1;
            }
            
             if(y+1 < grid[0].size() && grid[x][y+1]  == 0){
                q.push({x, y+1});
                  grid[x][y+1] = 1;
            }
            
             if(x-1 >= 0 && grid[x-1][y]  == 0){
                q.push({x-1, y});
                 
                  grid[x-1][y] = 1;
            }
            
            
             if(y-1 >= 0 && grid[x][y-1]  == 0){
                q.push({x, y-1});
                  grid[x][y-1] = 1;
            }
        }
        
        return flag;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int numIslands = 0;
        int s = 0;
        
        for(int index = 0; index < grid.size(); index++){
            
            for(int j = 0; j < grid[0].size(); j++){
                
                if(grid[index][j] == 0){
                    s++;
                    if(bfs(grid, index, j)){
                    numIslands++;
                    }
                }
            }
        }
        
        
        return numIslands;
    }
};