class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        int len = prerequisites.size();
        
        vector<int>ans;
        
        queue<int>bfs;
        vector<int>indegree(numCourses, 0);
        
        vector<int>adj[numCourses];
        
        for(int index = 0; index < len; index++){
            
            adj[prerequisites[index][1]].push_back(prerequisites[index][0]);
            indegree[prerequisites[index][0]]++;
        }
        
        for(int index = 0; index < numCourses; index++){
            
            if(indegree[index] == 0){
                bfs.push(index);
            }
        }
        
        cout<<bfs.size();
        while(!bfs.empty()){
            
            int node = bfs.front();
            ans.push_back(node);
            bfs.pop();
            
            for(auto it:adj[node]){
                
                indegree[it]--;
                
                if(indegree[it] == 0){
                    
                    bfs.push(it);
                }
            }
        }
        
        
        if(ans.size() < numCourses){
            
            return {};
        }
        
        return ans;
        
    }
};