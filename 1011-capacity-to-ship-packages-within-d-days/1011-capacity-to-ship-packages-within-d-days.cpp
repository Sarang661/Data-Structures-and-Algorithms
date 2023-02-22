class Solution {
    
    private:
    bool poss(vector<int>&weights, int weight, int maxDays){
        
        int currWeight = 0;
        int totalDays = 1;
     
        for(int index = 0; index < weights.size(); index++){
            
            if(currWeight > weight){
                return false;
            }
            
            else if((currWeight+weights[index])>weight){
                currWeight = weights[index];
                totalDays++;
            }
            else{
                
                currWeight += weights[index];
            }
        }
        
        return totalDays<=maxDays && currWeight<=weight;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = 1;
        int high = accumulate(weights.begin(), weights.end(), high);
        
        
     while(low<high){
         
         int m = low + (high-low)/2;
         
         if(poss(weights, m, days)){
         
             high = m;
         }
         else{
             low = m+1;
         }
     }
        
        return low;
    }
};