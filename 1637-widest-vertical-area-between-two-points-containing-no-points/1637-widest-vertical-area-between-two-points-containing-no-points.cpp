class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        
        int maxArea = 0;
        
        for(int index = 1; index < points.size(); index++){
            
            maxArea = max(maxArea, points[index][0]-points[index-1][0]);
        }
        
        
        return maxArea;
    }
};