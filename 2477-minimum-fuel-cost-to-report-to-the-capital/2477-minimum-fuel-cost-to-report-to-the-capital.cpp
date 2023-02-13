class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        long long n = roads.size() + 1;
        vector<int>adj[n];
        
        for(int index = 0; index < roads.size(); index++){
            adj[roads[index][0]].push_back(roads[index][1]);
            adj[roads[index][1]].push_back(roads[index][0]);
        }
        
        long long fuel = 0;
    
        
        dfs(adj, roads, fuel, seats, 0, -1);
       
        return fuel;
    }
    
    long long dfs(vector<int>adj[], vector<vector<int>>&roads, long long &fuel, int &seats, int currCity, int prevCity){
        
        long long currPeople = 1;
       
        for(auto num:adj[currCity]){
             
            if(num != prevCity){
       
                currPeople += dfs(adj, roads, fuel, seats, num, currCity);
            }
        }
        
        if(currCity!=0){
            fuel += ceil((double)currPeople/(double)seats);
        }
        
        return currPeople;
    }
};