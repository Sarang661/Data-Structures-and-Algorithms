class Solution {

private:
    
    bool static myCmp(vector<int>&a, vector<int>&b){
        
        return a[1] < b[1];
    }
    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        priority_queue<pair<int,int>>time;
        
        int len = courses.size();
        int currTime = 0;
  
        
        sort(courses.begin(), courses.end(), myCmp);
        
     
        for(int index = 0; index < courses.size(); index++){
          
            if(courses[index][0]+currTime <= courses[index][1]){
                time.push({courses[index][0], courses[index][1]});
                currTime +=courses[index][0];
            }
            else if(!time.empty() && time.top().first > courses[index][0]){
                   currTime +=courses[index][0];
                 time.push({courses[index][0], courses[index][1]});
                   currTime -= time.top().first;
                time.pop();
            }
            
        }
        
        return time.size();
        
    }
};