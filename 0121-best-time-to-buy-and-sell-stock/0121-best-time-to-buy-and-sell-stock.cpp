class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int curr = prices[0];
        
        int len = prices.size();
        int ans = 0;
        int currVal = ans;
        
        for(int index = 1; index < len; index++){
            curr = min(curr, prices[index]);
            
            currVal = prices[index] - curr;
            ans = max(ans, currVal);
            
        }
        
        return ans;
    }
};