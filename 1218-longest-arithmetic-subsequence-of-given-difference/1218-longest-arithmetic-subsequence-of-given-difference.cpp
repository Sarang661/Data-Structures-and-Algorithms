class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int len = arr.size();
        
       map<int,int>dp;
       
        
        int maxi = 0;
        
        for(int i = 0; i <len; i++){
            
            if(dp.find(arr[i]-difference)==dp.end()){
                dp[arr[i]] = 1;
            }
            else{
                dp[arr[i] ]= 1 + dp[arr[i]-difference];
                
                }
            maxi = max(maxi, dp[arr[i]]);
        }
        
        return maxi;
    }
};