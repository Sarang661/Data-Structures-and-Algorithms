class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<int>>adj[n];
        
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        vector<int>dist(n,1e9);
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        
        q.push({0,0,src});
        
        dist[src] = 0;
        while(q.empty()== false){
            int stops = q.top()[0];
            int val = q.top()[1];
            int node = q.top()[2];
            q.pop();
            if(stops > k){
                continue;
            }
            for(auto num:adj[node]){
                int node2 = num[0];
                int val2 = num[1];
                
                if(dist[node2] > val + val2){
                       
                    dist[node2] = val + val2;
                    q.push({stops+1,dist[node2], node2});
                }
            }
        }
        
        if(dist[dst] == 1e9){
            return -1;
        }
        
        return dist[dst];
        
    }
};