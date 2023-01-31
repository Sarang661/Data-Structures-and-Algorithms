class Solution {

    int find(vector<vector<int>>&v,vector<vector<int>>&dp,int n, int i, int minAge){
        if(i==0){
            if(minAge>=v[i][1]){
                return dp[i][minAge] = v[i][0];
            }
            return dp[i][minAge] = 0;
        }
        

        if(dp[i][minAge]!= -1){
            return dp[i][minAge];
        }
        
        if(v[i][1] <= minAge){
            dp[i][minAge] = v[i][0]+find(v,dp,n,i-1,min(minAge,v[i][1]));
        }
        return dp[i][minAge] = max( dp[i][minAge] ,  find(v,dp,n,i-1, minAge));
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>v;
        
        int n = scores.size();
        int maxi = 0;
        for(int i=n-1;i>=0;i--){
            v.push_back({scores[i],ages[i]});
            maxi = max(maxi,ages[i]);
        }
        vector<vector<int>>dp(n,vector<int>(maxi+2,-1));
        sort(v.begin(),v.end());
      return  find(v,dp,n,n-1, maxi+1);
    }
};