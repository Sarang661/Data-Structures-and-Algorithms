class Solution {
private:
    
    int bfs(vector<vector<int>>&grid, int i, int j){
        
        queue<pair<int,int>>q;
        
        q.push({i,j});
        grid[i][j] = 0;
        bool flag = false;
        int val = 0;
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            val++;
            if(x+1 >= grid.size() || y+1 >= grid[0].size() || y-1 < 0 || x-1 < 0){
                flag = true;
            }
            
            if(x+1 < grid.size() && grid[x+1][y] == 1){
                q.push({x+1,y});
                grid[x+1][y] = 0;
            }
            
            if(y+1 < grid[0].size() && grid[x][y+1] == 1){
                q.push({x,y+1});
                grid[x][y+1] = 0;
            }
            
            if(x-1 >= 0 && grid[x-1][y] == 1){
                q.push({x-1,y});
                grid[x-1][y] = 0;
            }
            
            if(y-1 >= 0 && grid[x][y-1] == 1){
                q.push({x,y-1});
                grid[x][y-1] = 0;
            }
        }
        
        if(flag){
            return 0;
        }
        
        return val;
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            
            for(int j = 0; j < grid[0].size(); j++){
                
                if(grid[i][j]){
                    
                    int numCells = bfs(grid, i, j);
                    ans += numCells;
                }
            }
        }
        
        return ans;
    }
};