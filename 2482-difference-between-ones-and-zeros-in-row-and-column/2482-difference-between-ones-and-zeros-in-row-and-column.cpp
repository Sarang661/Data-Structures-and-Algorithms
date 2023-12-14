class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        vector<int>rowOnes(grid.size(), 0);
        vector<int>colOnes(grid[0].size(), 0);
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < grid.size(); i++){
            
            for(int j = 0; j < grid[0].size(); j++){
                
                if(grid[i][j] == 1){
                    
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }
        
        vector<vector<int>>ans(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i = 0; i < grid.size(); i++){
            
            for(int j = 0 ; j < grid[0].size(); j++){
                
                int currScore = (rowOnes[i] + colOnes[j]) - (n - rowOnes[i] + m - colOnes[j]);
                ans[i][j] = currScore;
            }
        }
        
        
        return ans;
    }
};