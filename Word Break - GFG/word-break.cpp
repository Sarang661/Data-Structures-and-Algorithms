//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    
    private:
    
    bool canBePartitioned(int index, set<string>&st, vector<int>&dp, string &A){
        
        if(index == A.size()){
            return true;
        }
        
        if(dp[index]!= -1){
            return dp[index];
        }
        
        int maxi = 0;
        
        for(int j = index; j< A.size(); j++){
            if(st.find(A.substr(index,j-index+1))!=st.end()){
                maxi = max(maxi, (int)canBePartitioned(j+1, st, dp, A));
            }
        }
        
        return dp[index] =  maxi;
    }
public:
    int wordBreak(string A, vector<string> &B) {
        set<string>st;
        
        int n  = A.size();
        
        for(int index = 0; index < B.size(); index++){
            st.insert(B[index]);
        }
        
        vector<int>dp(n,-1);
        
        return canBePartitioned(0, st, dp, A);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends