class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
    /*  [[10,16],[2,8],[1,6],[7,12]]  ->  [[1,6], [2,8], [7,12], [10,16]] -> 
    
    traverse and while traversing will keep track of minimum start point   
    
    min = 1    arrows -> 1,  min = 1 and start of [2,8] -> 2 <= 6  -> [7, 12] and start is greater than 6 then we will increase the arrow number
    
    */
        sort(points.begin(), points.end());
        
        
        
        int len = points.size();
        int numArrows = 1;
        int mini = points[0][1];
    
        for(int index = 1; index < len ; index++){
            
            if(points[index][0] <= mini){
                
                mini = min(points[index][1], mini);
                continue;
            }
            else{
                numArrows++;
                mini = points[index][1];
            }
        }
        
        return numArrows;
    
    }
};