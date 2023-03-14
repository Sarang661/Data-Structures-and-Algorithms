class Solution {
private:
    
  
    
    bool find(vector<vector<int>>&dp, int n, int index, int k, vector<int>&stones, map<int,int>&indexes){
        
        if(index==(n-1)){
            return true;
        }
        
          if(index>=(n)){
            return false;;
        }
        
     
        if(dp[index][k]!= -1){
            return dp[index][k];
        }
        
       
        bool j1 = false;
        bool j2 = false;
        bool j3 = false;
        
        if(k>1 && indexes.find(stones[index]+(k-1)) != indexes.end()) {
            
            j1 = find(dp, n, indexes[stones[index]+(k-1)], k-1, stones, indexes);
        }
        
          if(k>0 && indexes.find(stones[index]+k) != indexes.end()) {
            
            j2 = find(dp, n, indexes[stones[index]+k], k, stones, indexes);
        }
        
        
          if(indexes.find(stones[index]+(k+1)) != indexes.end()) {
            
            j3 = find(dp, n, indexes[stones[index]+(k+1)], k+1, stones, indexes);
        }
        
        
        
        return dp[index][k] = (j1 || j2 || j3);
    }
public:
    bool canCross(vector<int>& stones) {
        
       
        int n = stones.size();
        map<int,int>indexes;
        
        for(int index = 0; index < n; index++){
            indexes[stones[index]] = index;
        }
        vector<vector<int>>dp(n,vector<int>(n+1, -1));
        
        return  find(dp, n, 0, 0, stones, indexes);
    }
};