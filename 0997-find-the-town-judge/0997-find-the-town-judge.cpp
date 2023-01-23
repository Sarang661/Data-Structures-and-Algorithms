class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int>adj(n+1,0);
        
        for(int i=0;i<trust.size();i++){
            adj[trust[i][1]]++;
              adj[trust[i][0]]--;
        }
       for(int i=1;i<=n;i++){
           if(adj[i] == n-1){
               return i;
           }
       }
        
        
        return -1;
    }
};