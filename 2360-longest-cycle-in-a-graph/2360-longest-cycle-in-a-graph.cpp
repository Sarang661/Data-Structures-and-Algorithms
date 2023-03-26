class Solution {
    int maxi = -1;
    
    void dfs(vector<int>adj[], vector<int>&dis, vector<int>&visited, int node, int curr){
        
        visited[node] = 1;
        dis[node] = curr;
        
        for(auto num:adj[node]){
            
            if(!visited[num]){
                dfs(adj, dis, visited, num, curr+1);
            }
            
            else if(visited[num] &&  dis[num]!= -1){
                maxi = max(maxi, dis[node]-dis[num]+1);
            }
        }
        
        dis[node] = -1;
    }
public:
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        vector<int>adj[n];
        
        for(int index  = 0; index < edges.size(); index++){
            
            if(edges[index]!= -1){
                adj[index].push_back(edges[index]);
            }
        }
        
        vector<int>dis(n,-1);
        vector<int>vis(n,0);
        
        for(int index = 0; index < n; index++){
            
            if(!vis[index]){
                
                dfs(adj, dis,vis, index, 0);
            }
        }
        
        return maxi;
    }
};