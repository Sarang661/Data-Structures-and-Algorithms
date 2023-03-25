class Solution {
    
private:

    void dfs(vector<long long>adj[], int node, vector<int>&visited, long long &val){
        
        val++;
        visited[node] = 1;
        
        for(auto num: adj[node]){
            
            if(!visited[num]){
                dfs(adj, num, visited, val);
            }
        }
        
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        long long ans = 0;
        
        vector<long long>adj[n];
        
        for(int index = 0; index < edges.size(); index++){
            
            adj[edges[index][0]].push_back(edges[index][1]);
             adj[edges[index][1]].push_back(edges[index][0]);
        }
        
      
        vector<int>visited(n, 0);
        
        long long sum = 0;
         long long val = 0;
        
        for(int index = 0; index < n; index++){
            
            if(!visited[index]){
                val = 0;
                dfs(adj, index, visited, val);
                ans += val*sum;
                sum+=val;

            }
          
        }
        
      
        
        return ans;
    }
};