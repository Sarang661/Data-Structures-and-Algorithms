//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long long countWays(int n, int k){
        
        vector<vector<long long>>dp(2,vector<long long>(n));
      
        long long MOD = 1e9 + 7;
        
        dp[0][0] = 0;
        dp[1][0] = k;
        
        for(int index = 1; index < n; index++){
            
            dp[0][index] = dp[1][index-1];
            dp[1][index] = ((k-1)*(dp[0][index-1] + dp[1][index-1]))%MOD;
        }
       
        return ( dp[0][n-1] + dp[1][n-1] )%MOD;
        
    
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends