class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>dis(n,1e9);
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        vector<vector<int>>adj[n];
        
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        q.push({0,0,src});
        
        dis[src]  = 0;
        
        while(q.empty()==false){
            
            int numStops = q.top()[0];
            int distance = q.top()[1];
            int node = q.top()[2];
            q.pop();
            
            // cout<<numStops<<" "<<distance<<" "<<node<<"\n";
            for(auto num:adj[node]){
                
                int dist = num[1];
                int node2 = num[0];
     
                if(dis[node2] > dist + distance && numStops < (k+1)){
                    
                    if(numStops+1 == (k+1) && node2!=dst){
continue;}
                    dis[node2] = dist + distance;
                    // cout<<numStops<<" "<<node2<<" "<<dis[node2]<<"\n";
                    q.push({numStops+1,dis[node2],node2});
                }
            }
        }
                
       
        
        if(dis[dst]==1e9){
            return -1;
        }

        return dis[dst];
    }
};