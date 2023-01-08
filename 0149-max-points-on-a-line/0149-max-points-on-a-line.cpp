class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        map<double, int>slope;
        
        int len = points.size();
        int maxPoints = 0;
        
        for(int index = 0; index < len ; index++){
            
            double x = points[index][0];
            double y = points[index][1];
            slope.clear();
            
            for(int j = 0; j < len; j++){
                
                if(points[index] == points[j]){
                    continue;
                }
                
                 double sl = 0.0;
                
                if(points[index][0] == points[j][0]){
                    sl = INT_MAX;
                }
                else{
                sl = (double)(y - points[j][1])/(double)(x-points[j][0]);
                }
                
                
                
                slope[sl]++;
                maxPoints = max(maxPoints, slope[sl]);
            }
        }
        

        
 
        
        return maxPoints + 1;
    }
};