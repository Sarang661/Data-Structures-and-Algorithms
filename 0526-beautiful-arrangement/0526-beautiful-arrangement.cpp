class Solution {
    
    int find(vector<int>&dp, int index, int n, set<int>&st){
        if(index==0){
            return 1;
        }
        
        int ans = 0;
        
        if(dp[index]!= -1){
            return dp[index];
        }
        for(int i =1; i<= n; i++){
            
            if(st.find(i) == st.end() && ((i%index == 0) || (index%i == 0))){
                st.insert(i);
               ans+= find(dp, index-1,n, st );
                st.erase(i);
            }
        }
        
        return ans;
    }
public:
    int countArrangement(int n) {
        vector<int>dp(n+1, -1);
        set<int>st;
        return find(dp, n, n, st);
    }
};