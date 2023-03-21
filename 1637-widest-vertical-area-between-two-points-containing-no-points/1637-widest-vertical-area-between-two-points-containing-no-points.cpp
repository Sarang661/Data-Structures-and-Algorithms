class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        
        int maxi = 0;
        
        for(int index = 0; index < points.size()-1; index++){
            
            maxi = max(maxi, points[index+1][0] - points[index][0]);
        }
        
        return maxi;
    }
};