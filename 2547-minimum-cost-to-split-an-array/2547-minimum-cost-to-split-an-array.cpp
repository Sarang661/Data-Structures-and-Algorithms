class Solution {
  int dp[1001];
  int v[1001][1001];
         
    int findMinCost(vector<int>&nums, int n, int k,int index){
        
        if(index >= n){
            return 0;
        }
        
        if(dp[index]!= -1){
            return dp[index];
        }
        
        int mini = INT_MAX;
        
        for(int i=index; i<n;i++){
            mini = min(mini, v[index][i] + findMinCost(nums, n,k,i+1));
        }
        
     return   dp[index] = mini;
    }
public:
    int minCost(vector<int>& nums, int k) {
        
        int n = nums.size();
        
       memset(dp, -1, sizeof(dp));
        
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
        

       
        
        findMinCost(nums, n, k,0);
        return dp[0];
    }
};