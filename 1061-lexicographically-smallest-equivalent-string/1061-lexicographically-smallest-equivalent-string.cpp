class Solution {
    
private:
    
    int findParent(int node, vector<int>&parent){
        
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findParent(parent[node], parent);
    }
    
    
 void unions(int node1, int node2, vector<int>&parent){
     
     int par1 = findParent(node1, parent);
     int par2 = findParent(node2, parent);
     
    
        
         parent[max(par1, par2)] = min(par1, par2);
       
 }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        vector<int>parent(26,-1);
        
        
        for(int index = 0; index < 26; index++){
            
            parent[index] = index;
        }
        
        for(int index = 0; index < s1.size(); index++){
            
            // cout<<s1[index]-'a'<<" "<<s2[index]-'a'<<"\n";
        
            unions(s1[index]-'a', s2[index]-'a', parent);
        }
       
        
    
        
        for(int index = 0; index < baseStr.size(); index++){
            
            int curr = findParent(baseStr[index]-'a', parent);
            
            baseStr[index] = (char)(curr+'a');
        }
        
        return baseStr;
    }
};