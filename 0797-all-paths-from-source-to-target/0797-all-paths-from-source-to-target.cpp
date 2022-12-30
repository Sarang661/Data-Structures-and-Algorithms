class Solution {

private:
    
    void findAllPaths(vector<int>adj[], vector<vector<int>>&allPaths, int numNodes, int node, vector<int>&currPath, vector<int>&visited){
        
        if(node == numNodes){
            
            currPath.push_back(node);
            allPaths.push_back(currPath);
            currPath.pop_back();
          
            return;
        }
        
        visited[node] = 1;
        
        currPath.push_back(node);
        
        for(auto num: adj[node]){
            
            if(!visited[num]){
              
                findAllPaths(adj,allPaths,numNodes,num,currPath,visited);
            }
        }
        
           visited[node] = 0;
        currPath.pop_back();
        
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int numNodes = graph.size();
        
        vector<vector<int>>allPaths;
        vector<int>adj[numNodes];
        vector<int>currPath;
        vector<int>visited(numNodes,0);
        
        
        for(int index = 0; index < numNodes; index++){
            
            for(auto num: graph[index]){
                adj[index].push_back(num);
            }
        }
        
        findAllPaths(adj, allPaths, numNodes-1, 0, currPath, visited);
        
        return allPaths;
    }
};