class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        

        int currTime = 1;
        int len =  tasks.size();
        vector<int>ans;
     
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minTime;
        
        vector<vector<int>>time;
        
        for(int index = 0; index < len; index++){
            
            time.push_back({tasks[index][0],tasks[index][1],index});
        }
        int index = 0;
           sort(time.begin(),time.end());
        
     while(index<len) {
            
            while(index< len && currTime>=time[index][0]){
                minTime.push({time[index][1],time[index][2]});
                index++;
            }
            
            if(!minTime.empty()){
                
                int t = minTime.top().first;
                int index = minTime.top().second;
                
                currTime += t;
                ans.push_back(index);
                minTime.pop();
            }
            else{
                currTime = time[index][0];
            }
        }

        while(!minTime.empty()){
            
         
                int index = minTime.top().second;
             ans.push_back(index);
                minTime.pop();
                
        }
        
       
    
        return ans;
        
    }
};