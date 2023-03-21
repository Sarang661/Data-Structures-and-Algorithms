class Solution {
    
    void dfs(vector<int>adj[], vector<int>&visited, int node){
        visited[node] = 1;
        
        for(auto num: adj[node]){
            
            if(!visited[num]){
                dfs(adj, visited, num);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int len = connections.size();
        
        if(len < (n-1)){
            return -1;
        }
        
        vector<int>adj[n];
        
        for(int index = 0; index < len; index++){
            adj[connections[index][0]].push_back(connections[index][1]);
            adj[connections[index][1]].push_back(connections[index][0]);
        }
        
        vector<int>visited(n,0);
        
        int ans = 0;
        
        for(int index = 0; index < n; index++){
            
            if(!visited[index]){
                ans++;
                
                dfs(adj,visited,index);
            }
        }
        
        return ans-1;
    }
};