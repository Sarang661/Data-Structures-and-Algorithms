class Solution {
private:
    
    void findTotalCount( int n, string &labels, vector<int>adj[], int node, vector<int>&freq, vector<int>&ans, int parent){
        
        int initial = freq[labels[node]-'a'];
        
       
         freq[labels[node]-'a']++;
            
        for(auto num: adj[node]){
            if(num == parent){
                continue;
            }
            
            findTotalCount(n, labels, adj, num, freq, ans, node);
        }
        
        ans[node] =  freq[labels[node]-'a'] - initial;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int>freq(26, 0);
        
        vector<int>adj[n];
        vector<int>ans(n,0);
        
        for(int index = 0; index < edges.size(); index++){
            
            adj[edges[index][0]].push_back(edges[index][1]);
             adj[edges[index][1]].push_back(edges[index][0]);
        }
        
        findTotalCount(n,labels, adj, 0, freq, ans, -1);
        
        return ans;
    }
};