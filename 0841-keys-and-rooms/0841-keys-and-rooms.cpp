class Solution {
private:
    
    void visitAllRooms(vector<int>adj[], vector<int>&visited, int node){
        
        visited[node] = 1;
        
        for(auto num: adj[node]){
            
            if(!visited[num]){
                
                visitAllRooms(adj, visited, num);
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