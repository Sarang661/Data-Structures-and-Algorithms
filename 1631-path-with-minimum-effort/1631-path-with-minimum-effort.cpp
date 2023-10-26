class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
        
        visited[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>minEffort;
        
        minEffort.push({0, 0, 0});
        
        int x[4] = {0, 0, -1, 1};
        int y[4] = {1, -1, 0, 0};
        
        while(!minEffort.empty()){
            
            int x1 = minEffort.top()[1];
            int y1 = minEffort.top()[2];
            int currEffort = minEffort.top()[0];
       
            if( x1 ==(n-1) && y1 == (m-1)){
                
           
                return minEffort.top()[0];
                
            }
            
                 minEffort.pop();
            
            for(int index = 0; index < 4; index++){
                
                int curr_x = x[index] + x1;
                int curr_y = y[index] + y1;
           
                
                if(curr_x >=0 && curr_x < n && curr_y >= 0 && curr_y < m){
                    
                    int h1 = heights[x1][y1];
                    int h2 = heights[curr_x][curr_y];
                    
                    int maxi = max(abs(h1-h2),currEffort );
                    
                    if(visited[curr_x][curr_y] > maxi){
                        
           
                        minEffort.push({maxi, curr_x, curr_y});
                        visited[curr_x][curr_y] = maxi;
                    }
                }
            }
            
        }
        
        return -1;
            
    }
};