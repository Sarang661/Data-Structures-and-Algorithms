class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>>flood;
        
        flood.push({sr,sc});
        int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        
        int startingColor = image[sr][sc];
        image[sr][sc] = color;
        
        while(!flood.empty()){
            
            int x = flood.front().first;
            int y = flood.front().second;
            flood.pop();
            for(int index = 0; index < 4; index++){
                
                int newX = x + dir[index][0];
                int newY = y + dir[index][1];
                
                if(newX < 0 || newY < 0 || newX >=n || newY>=m || image[newX][newY]==color || image[newX][newY]!=startingColor){
                    continue;
                }
                image[newX][newY] = color;
                flood.push({newX,newY});
            }
        }
        
        return image;
    }
};