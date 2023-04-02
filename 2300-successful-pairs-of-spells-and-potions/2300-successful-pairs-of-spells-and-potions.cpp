class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());
        
        vector<int>ans(spells.size());
        
        long long div = 0;
        
        for(int index = 0; index < spells.size(); index++){
            
            div = success/(long long)spells[index];
            
            if(success%(long long)spells[index] != 0){
                div++;
            }
            auto it = lower_bound(potions.begin(), potions.end(), div);
            
            ans[index] = potions.end()-it;
        }
        
        return ans;
    }
};