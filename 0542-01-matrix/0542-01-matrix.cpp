class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>>q;
        
        int m = mat.size();
        int n = mat[0].size();
        
        for(int index = 0; index < m; index++){
            
            for(int j = 0; j < n; j++){
                
                if(mat[index][j] == 0){
                    q.push({index, j, 0});
                }
                else{
                    mat[index][j] = -1;
                }
            }
        }
        
        int x_dir[4] = {0, 0, -1, 1};
        int y_dir[4] = {1, -1, 0, 0};
        
        while(!q.empty()){
            
            int dis = q.front()[2];
            int x = q.front()[0];
            int y = q.front()[1];
            
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int new_X = x + x_dir[i];
                int new_Y = y + y_dir[i];
                
                if(new_X < 0 || new_Y < 0 || new_X >= m || new_Y >= n || mat[new_X][new_Y]!= -1){
                    continue;
                }
                
                q.push({new_X, new_Y, dis+1});
                mat[new_X][new_Y] = dis + 1;
            }
        }
        
        return mat;
    }
};