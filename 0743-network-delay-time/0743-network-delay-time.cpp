class Solution {
    
    int findMinTime(vector<pair<int,int>>adj[], int k, int n){

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minDist;
	
vector<int>dist(n+1, INT_MAX);

  
dist[k] = 0;

minDist.push({0, k});

while(!minDist.empty()){
	
	int currNode = minDist.top().second;
	int currDist = minDist.top().first;
	minDist.pop();
        
     
	for(auto num: adj[currNode]){
	
     
		if(dist[num.first] > (currDist + num.second)){
			
          

            dist[num.first] = currDist + num.second;

             minDist.push({ currDist+ num.second, num.first});
            
		}
	}

}

int netWorkDelayTime = INT_MIN;


for(int index = 1; index <= n; index++){
	
  
netWorkDelayTime = max(netWorkDelayTime, dist[index]);
	
}

        
        if(netWorkDelayTime == INT_MAX){
            
            netWorkDelayTime = -1;
        }
return netWorkDelayTime;

}

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>adj[n+1];


for(int index =0; index < times.size(); index++){

adj[times[index][0]].push_back({times[index][1], times[index][2]});
}

       
return findMinTime(adj, k, n);

    }
};