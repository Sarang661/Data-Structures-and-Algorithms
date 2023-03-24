class Solution {
private:
    
    int ans = 0;
    
    void dfs(vector<vector<int>>adj[], vector<int>&visited, int node){
        
        visited[node] = 1;
        
        for(auto num:  adj[node]){
            
            if(!visited[num[0]]){
                
                 if(num[1] == node){
                    ans++;
                }
                dfs(adj, visited, num[0]);
            }
           
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>adj[n];
        
        for(int index = 0; index < connections.size(); index++){
            adj[connections[index][0]].push_back({connections[index][1], connections[index][0], connections[index][1]});
            
            adj[connections[index][1]].push_back({connections[index][0], connections[index][0], connections[index][1]});
        }
        
        
        vector<int>visited(n,0);
        
        dfs(adj, visited, 0);
        
        return ans;
    }
};