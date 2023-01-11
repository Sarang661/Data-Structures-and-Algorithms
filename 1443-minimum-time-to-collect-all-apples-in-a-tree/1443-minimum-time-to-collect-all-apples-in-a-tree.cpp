class Solution {

private:
    
    bool findTotalTime(int n, vector<int>adj[], vector<bool>& hasApple, int &timeReq, int node, vector<int>&vis){
        
        if(adj[node].size() == 0){
          
            return hasApple[node] == true;
        }
        
        bool curr = false;
        vis[node] = 1;
        
        for(int index = 0; index < adj[node].size(); index++){
            
            timeReq+=2;
            bool check = false;
            
            if(vis[adj[node][index]] == 0){
          check = findTotalTime(n, adj, hasApple, timeReq, adj[node][index], vis);
            }
            
            if(!check){
                  timeReq-=2;
            }
            else{
                curr = true;
            }
        }
        
        return (curr || (hasApple[node] == true));
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        int timeReq = 0;
        vector<int>adj[n];
        vector<int>vis(n, 0);
        for(int index = 0; index < edges.size(); index++){
            
            adj[edges[index][0]].push_back(edges[index][1]);
            adj[edges[index][1]].push_back(edges[index][0]);
            
        }
        
        findTotalTime(n, adj, hasApple, timeReq, 0, vis);
        
        return timeReq;
    }
};