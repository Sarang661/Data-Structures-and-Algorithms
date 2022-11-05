class Solution {
private:
    bool findWord(vector<vector<char>>& board, string &word, int index,int row, int col, int numRows, int numCols,vector<vector<int>>&visited){
        
          if(index == word.size()){
            return true;
        }

        if(row<0 || col<0 || row>=numRows || col>=numCols || (visited[row][col] == 1)){
            return false;
        }
        
        if((word[index] != board[row][col])){
            return false;
        }

        visited[row][col] = 1;
        
        int dir1 = findWord(board, word, index+1, row+1, col, numRows, numCols, visited);
        int dir2 = findWord(board, word, index+1, row-1, col, numRows, numCols, visited);
        int dir3 = findWord(board, word, index+1, row, col+1,numRows, numCols, visited);
        int dir4 = findWord(board, word, index+1, row, col-1, numRows, numCols, visited);

        if(dir1 || dir2 || dir3 || dir4){
            return true;
        }

        visited[row][col] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int numRows = board.size();
        int numColumns = board[0].size();

        for(int row = 0; row < numRows; ++row){

            for(int col = 0; col<numColumns; ++col){
            cout<<row<<" "<<col<<"\n";
                if(board[row][col] == word[0]){
                      vector<vector<int>>visited(numRows,vector<int>(numColumns,0));
                bool isExist = findWord(board, word,0,row,col,numRows,numColumns,visited);
                if(isExist){
                    // cout<<"ihihiiihi";
                    return true;
                }
                }
            }
        }

        return false;
    }
};