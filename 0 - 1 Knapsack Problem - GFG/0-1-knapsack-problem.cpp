//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       vector<vector<int>>dp(n, vector<int>(W+1, 0));
       
       
      for(int index = wt[0]; index <= W; index++) {
           
           dp[0][index] = val[0];
       }
       
       for(int index = 1; index < n; index++){
           
           for(int weight = 1; weight <= W; weight++){
               
               dp[index][weight] = dp[index-1][weight];
               
               if(weight >= wt[index]){
                   
                   dp[index][weight] = max(dp[index][weight], val[index] + dp[index-1][weight-wt[index]]);
               }
           }
       }
       
       
       return dp[n-1][W];
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends