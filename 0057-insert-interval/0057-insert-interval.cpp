class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>ans;
        
        int len = intervals.size();
        if(len==0){
            return {{newInterval[0],newInterval[1]}};
        }
        int start = newInterval[0];
        int end = newInterval[1];
        
        for(int index = 0; index < len; index++){
            
            
              if(intervals[index][0] >= start && start!= -1){
                
                 ans.push_back({start, end});
                  start = -1;
                  
            } 
                
              ans.push_back({intervals[index][0],intervals[index][1]});
            
               if(index == len -1 && start != -1){
                
                 ans.push_back({start, end});
                  start = -1;
            } 
            
        
        }
        
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
        }
        start = -1 ;
        end = -1;
        
        vector<vector<int>>finals;
       int l = ans.size();
        for(int index = 0; index < l; index++){

            start = ans[index][0];
            end = ans[index][1];
            while(index < l-1 && ans[index+1][0]<=end){
                
                end = max(end,ans[index+1][1]);

                index++;
            }
            
      
            if(start != -1 && end != -1){
                finals.push_back({start, end});
                start = -1;
                end = -1;
                      
            }
            else{
            
                finals.push_back({ans[index][0],ans[index][1]});
            }
            
        }
        
        return finals;
    }
};