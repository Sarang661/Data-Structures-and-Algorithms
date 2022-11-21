class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>>q;
        int n = maze.size();
        int m = maze[0].size();
        q.push({entrance[0],entrance[1],0});
        vector<vector<int>>visited(n,vector<int>(m,0));
      
        while(!q.empty()){
            int x= q.front()[0];
            int y = q.front()[1];
            int val = q.front()[2];
          q.pop();
            if(x>=n || y>=m || x<0 || y<0 || maze[x][y]=='+'){
                continue;
            }
            if(visited[x][y]==1){
                continue;
            }

            visited[x][y] = 1;
            q.push({x+1,y,val+1});
            q.push({x,y+1,val+1});
            q.push({x-1,y,val+1});
            q.push({x,y-1,val+1});
            if(x==0 || y==0 ||x==(n-1) || y==(m-1)){
                  if(x==entrance[0] && y==entrance[1]){
                continue;
            }
                return val;
            }
        }
        
        
        return -1;
    }
};