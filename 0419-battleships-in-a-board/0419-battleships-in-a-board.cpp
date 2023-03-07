class Solution {
private:
    
    int X_dir[4] = {0, 0, -1, 1};
    int Y_dir[4] = { 1, -1, 0, 0};
    
    void dfs(vector<vector<char>>&board, int i, int j){
        
        if(i < 0 || j < 0 || i>= board.size() || j>= board[0].size() || board[i][j] == '.'){
            return;
        }
        

        board[i][j] = '.';
        
        for(int k = 0; k < 4; k++){
            
            dfs(board, i + X_dir[k], j + Y_dir[k]);
        }
        
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int ans = 0;
        
        int row = board.size();
        int col = board[0].size();
        
        for(int index = 0; index < row; index++){
            
            for(int j = 0; j < col; j++){
                
                if(board[index][j]=='X'){
                    ans++;
                    dfs(board, index, j);
                }
            }
        }
        
        return ans;
    }
};