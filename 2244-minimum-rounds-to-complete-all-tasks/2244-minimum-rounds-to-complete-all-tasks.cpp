class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        map<int,int>count;
        
        int len = tasks.size();
        
        for(int index = 0; index < len; index++){
            
            count[tasks[index]]++;
        }
        
        //  [2,2,3,3,2,4,4,4,4,4]  2,  3 ,  4
        
        int numRounds = 0;
        
        for(auto num:count){
            
            int curr = num.second;
            
             if(curr == 1){
                 
                 return -1;
             }
            else{
                
                numRounds += (curr +2)/3;
            }
        }
        
        return numRounds;
    }
};