class Solution {
public:
    int maxPalindromes(string s, int k) {
         int n =s.length();
     vector<vector<int>>dp(n,vector<int>(n,0));
        int row=0;
        int col=0;
   
for(int i=0;i<n;i++){
    int l=0;
    int r= i;
    while(r<n){
        if(i==0){
            dp[l][r]=1;
        }
        else if(i==1){
            if(s[l]==s[r]){
                 dp[l][r]=1;
            }
        }
        else{
            if(s[l]==s[r] && dp[l+1][r-1]==1){
                dp[l][r]=1;
            }
        }
        l++;
        r++;
    }
    }
        
        vector<int>dp2(n+1,0);
        for(int i=k;i<=n;i++){
            dp2[i]  = dp2[i-1];
            for(int j=i-(k-1);j>=1;j--){
                // cout<<i<<" "<<j<<"\n";
                
                if(dp[j-1][i-1]==1){
                    dp2[i] = max(dp2[j-1]+1,dp2[i]);
                }
               
            }
        }
       
        return dp2[n];
    }
};