class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int len = strs.size();
        int col = strs[0].size();
        
        string curr = "";
        int numCols = 0;
        string copy = "";
        
        for(int index = 0; index < col; index++){
            
            curr = "";
            
            for(int j = 0; j < len; j++){
                
                curr+=strs[j][index];
            }
            
            copy = curr;
            sort(copy.begin(), copy.end());
            
            if(copy != curr){
                
                numCols++;
            }
        }
        
        return numCols;
        
    }
};