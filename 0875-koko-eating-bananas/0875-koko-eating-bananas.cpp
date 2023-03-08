class Solution {
    
private:
    
    bool isposs(int curr, vector<int>&piles, int hours){
        
        int total =0;
        
        for(int i=0;i<piles.size();i++){
            total += (piles[i]/curr);
            if(piles[i]%curr != 0){
                total++;
            }
        }
        
        return total <= hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int len = piles.size();
        int low = 1;
        
        int high = *max_element(piles.begin(), piles.end());
        
        while(low < high){
            
            int mid = low + (high-low)/2;
            
            if(isposs(mid, piles,h)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};