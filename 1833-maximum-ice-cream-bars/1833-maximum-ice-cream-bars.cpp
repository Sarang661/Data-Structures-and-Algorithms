class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(),costs.end());
        
        for(int index = 0; index < costs.size(); index++){
            
            if(coins>=costs[index]){
                
                coins = coins - costs[index];
            }
            else{
                
                return index;
            }
        }
        
        return costs.size();
    }
};