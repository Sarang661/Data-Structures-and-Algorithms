class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        
       priority_queue<int>q;
        
        int ans = 0;

        q.push(neededTime[0]);
        
        int index =1;
        
      while(index < colors.size()) {
            
           while(index < colors.size() && colors[index] == colors[index-1]){
                
                q.push(neededTime[index]);
               index++;
               continue;
                
            }
            
            q.pop();
            
            while(!q.empty()){
      
                ans += q.top();
                q.pop();
            }
            
            q.push(neededTime[index]);
          index++;
        }
        
           q.pop();
            
            while(!q.empty()){
      
                ans += q.top();
                q.pop();
            }
            
        
        return ans;
    }
};