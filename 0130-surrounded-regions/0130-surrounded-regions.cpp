class Solution {
    
    void bfs(vector<vector<char>>&board, int i, int j){
        
        queue<pair<int,int>>q;
        q.push({i,j});
        board[i][j] = '1';
        
        int dirX[4] = {0,1,-1,0};
        int dirY[4] = {1, 0, 0, -1};
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                
                if(newX < 0 || newY < 0 || newX >= board.size() || newY >= board[0].size()){
                    continue;
                }
                
                if(board[newX][newY] == 'O'){
                    q.push({newX, newY});
                    board[newX][newY] = '1';
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int row = board.size();
        int col = board[0].size();
        
        for(int index = 0; index < col; index++){
            
            if(board[0][index] == 'O'){
                bfs(board, 0, index);
            }
        }
        
         for(int index = 0; index < col; index++){
            
            if(board[row-1][index] == 'O'){
                bfs(board, row-1, index);
            }
        }
        
           for(int index = 0; index < row; index++){
            
            if(board[index][0] == 'O'){
                bfs(board, index, 0);
            }
        }
        
          for(int index = 0; index < row; index++){
            
            if(board[index][col-1] == 'O'){
             
                bfs(board, index, col-1);
            }
        }
        
        for(int index = 0; index < row; index++){
            
            for(int j = 0; j < col; j++){
                
                if(board[index][j] == 'O'){
                    board[index][j] = 'X';
                }
                  if(board[index][j] == '1'){
                    board[index][j] = 'O';
                }
            }
        }
        
       
    }
};