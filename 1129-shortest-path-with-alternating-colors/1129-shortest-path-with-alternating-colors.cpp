class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<pair<int,int>>adj[n];
        
        for(int index = 0; index < redEdges.size(); index++){
            
            adj[redEdges[index][0]].push_back({redEdges[index][1],0});
        }
        
          for(int index = 0; index < blueEdges.size(); index++){
            
            adj[blueEdges[index][0]].push_back({blueEdges[index][1],1});
        }
        
        queue<vector<int>>q;
        q.push({0,-1,0});
        vector<vector<int>>vis(n,vector<int>(2,0));
        
        vis[0][0] = 1;
        vis[0][1] = 1;
        
        vector<int>ans(n,-1);
        ans[0] = 0;
        while(!q.empty()){
            
            vector<int>curr = q.front();
            int node = curr[0];
            int prev = curr[1];
            int steps = curr[2];
            q.pop();
            for(auto num:adj[node]){
                
                int currNode = num.first;
                int color = num.second;
                
                if(vis[currNode][color] == 0 && color!=prev){
                    vis[currNode][color] = 1;
                    if(ans[currNode] == -1){
                        ans[currNode] = steps+1;
                    }
                    q.push({currNode,color,steps+1});
                }
            }
        }
        
        return ans;
    }
};