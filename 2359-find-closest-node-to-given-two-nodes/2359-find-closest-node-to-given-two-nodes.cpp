class Solution {
    
private:
    void findDistanceFromNode( int node, vector<int>&dist1, vector<int>adj[], int dist, vector<int>&visited){
        
        visited[node] = 1;
        dist1[node] = dist;
        
        dist++;
        
        for(auto num:adj[node]){
            
            if(visited[num] == 0){
            findDistanceFromNode( num, dist1, adj, dist, visited);
            }
        }
        
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int>dist1(n,-1);
        vector<int>dist2(n,-1);
        vector<int>visited(n,0);
        vector<int>adj[n];
        
        for(int index = 0; index < edges.size(); index++){
            
            if(edges[index] == -1){
                continue;
            }
            
            adj[index].push_back(edges[index]);
        }
        
        findDistanceFromNode( node1, dist1, adj, 0, visited);
        
        fill(visited.begin(), visited.end(), 0);
        
        findDistanceFromNode(node2, dist2, adj, 0, visited);
        
        int mini = INT_MAX;
        int node = -1;
        
        
     
        for(int i = 0; i < n; i++){
            
            if(dist1[i] != -1 && dist2[i] != -1){
                
                int curr = max(dist1[i], dist2[i]);
                
                if(curr < mini){
                    
                    mini = curr;
                    node = i;
                }
                else if( curr == mini){
                    
                    node = min(node, i);
                }
            }
        }
        
        return node;
    }
};