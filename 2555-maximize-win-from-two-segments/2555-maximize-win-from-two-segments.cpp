class Solution {
    int find(int index,vector<int>&prizePositions,int n, int k, vector<int>&dp){
        
        if(index == n){
            return 0;
        }
      
          if(dp[index]!= -1){
            return dp[index];
        }
        int start = index;
       int end = upper_bound(prizePositions.begin(),prizePositions.end(),prizePositions[index]+k)-prizePositions.begin();
            
  
       return  dp[index] = max(find(index+1,prizePositions,n,k,dp),end-start);
    }
    
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        
  
        int n = prizePositions.size();
        vector<int>dp(n,-1);
              int maxi = 0;
        
        for(int i=0;i<n;i++){
            int start = i;
                   int end = upper_bound(prizePositions.begin(),prizePositions.end(),prizePositions[i]+k)-prizePositions.begin();
     
            int curr = find(end,prizePositions,n,k,dp);

            maxi = max(maxi,(int) end-start+curr);
        }
      
        
        return maxi;
    }
};