class Solution {
public:
    int dfs(int node,int parent,vector<int> adj[],vector<bool>& hasApple){
        int time=0;
        for(auto &i:adj[node]){
            if(i!=parent)
                time+=dfs(i,node,adj,hasApple);
        }
        return (time||hasApple[node])? time+=2:0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto &i:edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=dfs(0,-1,adj,hasApple);
        return ans==0?ans:ans-2; 
    }
};