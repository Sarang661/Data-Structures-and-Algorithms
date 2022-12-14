//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
       map<int,int>postion;
 
       int currSum = 0;
       int maxLen = 0;
       
       postion[0] = -1;
       
       for(int index = 0; index < A.size(); index++){
           
           currSum += A[index];
           
           if(postion.find(currSum)!=postion.end()){
             
               maxLen = max(maxLen, index - postion[currSum]);
               
           }
           else{
               
               postion[currSum] = index;
           }
           
       }
        return maxLen;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends