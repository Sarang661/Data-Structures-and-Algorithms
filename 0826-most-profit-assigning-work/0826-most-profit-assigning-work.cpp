class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<vector<int>>profits;
        
        for(int index = 0; index < profit.size(); index++){
            profits.push_back({profit[index], difficulty[index]});
        }
        
        sort(profits.begin(), profits.end());
        sort(worker.begin(), worker.end());
        int lastIndex = worker.size()+1;
        
        int maxProfit = 0;
        
        for(int index = profits.size()-1; index >= 0; index--){
            
            auto it = lower_bound(worker.begin(), worker.end(), profits[index][1]);
            
            if(it == worker.end()){
                continue;
            }
            
            int curr = it - worker.begin()+1;
        
            
            if(lastIndex < curr){
                continue;
            }
            cout<<curr<<" "<<lastIndex<<"\n";
            
            
            maxProfit += (lastIndex - curr)*profits[index][0];
            
             lastIndex = min(lastIndex, curr);
        }
        
        return maxProfit;
    }
};