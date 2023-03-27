class Solution {
    
private:
    
    int findMinimumPathSum(vector<vector<int>>&dp, vector<vector<int>>&grid, int i, int j, int n, int m){
        
        if(i >= n || j >= m || i < 0 || j < 0){
            return 1e9;
        }
        
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = findMinimumPathSum(dp, grid, i, j+1, n, m);
        int down = findMinimumPathSum(dp, grid, i+1, j, n, m);
        
        return dp[i][j] = grid[i][j] + min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return findMinimumPathSum(dp, grid, 0, 0, n, m);
    }
};