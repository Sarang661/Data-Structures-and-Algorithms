class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<pair<int,int>>maxProfit;
        
        vector<vector<int>>cap;
        
        int maxCapital = 0;
        int currCapital = w;
        int len = profits.size();
        
        for(int index = 0; index < len; index++){
            
            cap.push_back({capital[index], profits[index]});
        }
        
        sort(cap.begin(), cap.end());
        
        int index = 0;
        maxProfit.push({0,0});
       
       while(!maxProfit.empty() && index < len && k > 0){
       
            while(index < len && cap[index][0] <= currCapital){
                
                maxProfit.push({cap[index][1], cap[index][0]});
                index++;
            }

           
           if(k > 0){
               currCapital += maxProfit.top().first;
               maxProfit.pop();
               k--;
               
           }
           
        }
        

     
        while(!maxProfit.empty() && k > 0){
            
            int currNeed = maxProfit.top().second;
            int currProfit = maxProfit.top().first;
            
            if(currNeed <= currCapital){
                currCapital += currProfit;
                k--;
            }
            
            maxProfit.pop();
        }
        
        return currCapital;
    }
};