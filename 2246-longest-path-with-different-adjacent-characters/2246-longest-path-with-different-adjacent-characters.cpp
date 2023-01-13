class Solution {
    
private:
    
    int findLongestPath(vector<int>adj[], string &s, int node, int &maxi){
        
        if(adj[node].size() == 0){
            return 1;
        }
        
        int curr = 0;
        int secondMax = 0;
           
        for(auto num: adj[node]){
            
            int val = findLongestPath(adj, s, num, maxi);
        
            if(s[node]!=s[num]){
                
                if(curr < val){
                    
                    secondMax = max(secondMax, curr);
                curr = max(curr, val);
                    
                }
                else{
                    secondMax = max(secondMax, val);
                }
            }
        }
        
        maxi = max(maxi, curr + secondMax + 1);
        
        return  curr + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        
        vector<int>adj[n];
        
        for(int i=1;i<n;i++){
            
            adj[parent[i]].push_back(i);
            
        }

        int maxi = 1;
        
        findLongestPath(adj, s, 0, maxi);
        return maxi;
    }
};