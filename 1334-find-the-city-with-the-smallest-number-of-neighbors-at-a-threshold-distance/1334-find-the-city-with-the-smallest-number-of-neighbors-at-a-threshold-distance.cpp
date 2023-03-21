class Solution {
    
    int findShortestDistance(int n, int node, vector<pair<int,int>>adj[], int maxDis){
        
        vector<int>distance(n, INT_MAX);
        
        distance[node] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>minDist;
        minDist.push({0,node});
        
        
        while(!minDist.empty()){
            
            int curr = minDist.top().second;
            int dist = minDist.top().first;
            minDist.pop();
            
            for(auto num:adj[curr]){
                
                if(dist+num.second < distance[num.first]){
                    distance[num.first] = dist+num.second;
                    minDist.push({dist+num.second, num.first});
                }
            }
        }
        
        int ans = 0;
        
        for(int index = 0; index < n; index++){
            if(index != node && distance[index] <= maxDis){
                ans++;
            }
        }
        
        return ans;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>>adj[n];
        
        for(int index = 0; index < edges.size(); index++){
            adj[edges[index][0]].push_back({edges[index][1], edges[index][2]});
            adj[edges[index][1]].push_back({edges[index][0], edges[index][2]});
        }
        
        int ans = 0;
        int mini = INT_MAX;
        
        for(int index = 0; index < n; index++){
            
            int curr = findShortestDistance(n, index, adj, distanceThreshold);
            
            if(curr <= mini){
                ans = max(ans, index);
                mini = curr;
            }
        }
        
        return ans;
    }
};