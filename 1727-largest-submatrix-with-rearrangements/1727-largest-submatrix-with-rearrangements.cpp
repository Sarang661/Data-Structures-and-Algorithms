class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        
 
        int len = matrix.size();
        int maxArea = 0;

        int mini = INT_MAX;
        
         vector<int>temp(matrix[0].size(),  0);
        
        for(int index = 0; index < matrix.size(); index++){
            
            for(int j = 0; j < matrix[0].size(); j++){
                    
                if(index > 0 && matrix[index-1][j] == 1){
                    
                    if(matrix[index][j] == 1){
                        
                        temp[j] = temp[j] +1;

                    }
                    else{
                        
                        temp[j] = 0;
                    }
                }
                
                else{
                    
                     temp[j] = matrix[index][j];
                }
            }
            
            vector<int>curr = temp;
            sort(curr.begin(),curr.end());
            reverse(curr.begin(), curr.end());
            int width = 0;
            mini = INT_MAX;
          
        
            for(int val = 0; val < curr.size(); val++){
                
                if(curr[val]>0){
                     mini = min(mini, curr[val]);
                    width++;
                       maxArea = max(maxArea, width*mini);
                  
                }
            }
     
        }
        
        return maxArea;
    }
};