class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int n = grid.size();
        
        int x_arr[4] = {0,-1,1, 0};
        int y_arr[4] = {1, 0, 0,-1};
  
        
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        
        int dis = -1;
        int maxi = 0;
        bool flag = false;
        
        while(q.empty()==false){
            
            int size = q.size();
            dis++;
            
            for(int index = 0; index < size; index++){
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                flag = false;
                
                for(int i = 0; i < 4;i++){
                    
                    int newX = x+x_arr[i];
                    int newY = y + y_arr[i];
                    
                    if(newX<0 || newY<0 || newX>=n || newY>=n || grid[newX][newY] == 1){
                        continue;
                    }
                    grid[newX][newY] = 1;
                    flag = true;
                    q.push({newX,newY});
                }
                
            }
            
            
        }
        
        if(dis==0){
            return -1;
        }
        return dis;
    }
};