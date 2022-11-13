class Solution {
private:
    bool isPal(int start, int end,string &s,vector<vector<int>>&dp){
        if(start>end){
            return 1;
        }
        if(dp[start][end]!= -1){
            return dp[start][end];
        }
        if(s[start]!=s[end]){
            return 0;
        }
        
      return dp[start][end] = isPal(start+1,end-1,s,dp);
    }
public:
    int maxPalindromes(string s, int k) {
         int n =s.length();
     vector<vector<int>>dp(n,vector<int>(n,-1));
        int row=0;
        int col=0;
   

        
        vector<int>dp2(n+1,0);
        for(int i=k;i<=n;i++){
            dp2[i]  = dp2[i-1];
            for(int j=i-(k-1);j>=1;j--){
                // cout<<i<<" "<<j<<"\n";
                
                if(isPal(j-1,i-1,s,dp)==1){
                    dp2[i] = max(dp2[j-1]+1,dp2[i]);
                }
               
            }
        }
       
        return dp2[n];
    }
};