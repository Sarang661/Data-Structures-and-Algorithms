class Solution {

public:
    int minCost(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<vector<int>>v(n,vector<int>(n));
        vector<int>dp(n+1, INT_MAX);
        dp[n] = 0;
        
        for(int i=0;i<n;i++){
            
            int currLen = 0;
            unordered_map<int,int>m;
            
            for(int j=i;j<n;j++){
                m[nums[j]]++;
               
               if(m[nums[j]]==2){
                     currLen++;
                     currLen++;
                }
                else if(m[nums[j]]>1){
                    currLen++;
                }
             
                v[i][j] = currLen + k;
            }
        }
        

       
        
     for(int i=n-1;i>=0;i--){
         for(int j=i;j<n;j++){
             
             dp[i] = min(dp[i], v[i][j]+dp[j+1]);
         }
     }
        return dp[0];
    }
};