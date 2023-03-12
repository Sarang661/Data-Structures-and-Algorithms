class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int len = rating.size();
        
        vector<int>dp(len, 0);
        
        int ans = 0;
        
        for(int index = 0; index < len; index++){
            
            for(int j = 0; j < index; j++){
                
                if(rating[index] > rating[j]){
                    dp[index]++;
                    ans+= dp[j];
                }
            }
        }
        fill(dp.begin(), dp.end(), 0);
        
        for(int index = len-1; index>=0; index--){
            
            for(int j= len-1; j > index; j--){
                
                if(rating[index] > rating[j]){
                    dp[index]++;
                    ans+=dp[j];
                }
            }
        }
        
        return ans;
    }
};