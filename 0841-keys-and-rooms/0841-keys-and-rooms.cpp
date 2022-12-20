class Solution {
private:
    
    void visitAllRooms(vector<int>adj[], vector<int>&visited, int node){

        queue<int>level;
        
        level.push(node);
        
        visited[node] = 1;
        
        while(!level.empty()){
            int size = level.size();
          
            for (int index = 0; index < size; index++){
                
                  int currNode = level.front();
            level.pop();
            
            for(auto num: adj[currNode]){
                
                if(!visited[num]){
                level.push(num);
                }
                visited[num] = 1;
                
            }
            }
            
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int numRooms = rooms.size();
        
        vector<int>adj[numRooms];
        
        // [[],[0]]
        
        for(int index = 0; index < numRooms; index++){
            
            for(int room = 0; room < rooms[index].size(); room++){
                
            adj[index].push_back(rooms[index][room]);
                
            }
            
        }
        
        vector<int>visited(numRooms,0);
        
        visitAllRooms(adj, visited, 0);
        
        for(int index = 0; index < numRooms; index++){
            
            if(!visited[index]){
                
                return false;
            }
        }
        
        
        return true;
    }
};