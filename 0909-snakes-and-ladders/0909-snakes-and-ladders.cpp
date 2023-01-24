class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // 28/ 6 = 4+1 = 5th Row  28 - 4*6 = 4   5th row and 4th Col  -> O index = 4th Row and 3rd Column
        
        int n = board.size();
        
        queue<vector<int>>currNum;
        
        vector<int>visited(n*n+1, 0);
        
        currNum.push({1,0});
        visited[1] = 1;
        
        if(n==1){
            return 0;
        }
        
        // Queue -> {position, steps};
        
        while(currNum.empty() == false){
            
            int curr = currNum.front()[0];
            int steps = currNum.front()[1];
               
            currNum.pop();
            
              if(curr == n*n){
                    return steps;
                }
            
            for(int index = 1; index <=6; index++){
                
                int pos = curr + index;

                if(pos > n*n || visited[pos] == 1){
                    continue;
                }
                
              
                    
                visited[pos] = 1;
                int nextRow = pos/n;
                 int nextCol = pos;
            
                int val = pos/n;
                if(pos%n == 0){
                    val--;
                }
            
              
              nextCol = pos - (n*val);
                    
             
                 
                
                if(pos%n!= 0){
                    nextRow++;
                }
              
                        
             // 3 1
                nextRow--;
                nextCol--;
                
                 nextRow = n - nextRow-1;
               
                if(n%2 ==1 && nextRow%2==1){
                    nextCol = n - nextCol;
                    nextCol--;
                }
               
                   if(n%2 ==0 && nextRow%2==0){
                    nextCol = n - nextCol;
                    nextCol--;
                }
                     
       
             
                
           
                if(board[nextRow][nextCol] == -1){
                                      
                    currNum.push({pos,steps+1});
                }
                else{
                    
                 
               
                    currNum.push({board[nextRow][nextCol], steps+1});
                }
            }
        }
        
        return -1;
    }
};