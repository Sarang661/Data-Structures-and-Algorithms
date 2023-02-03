class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        
      vector<vector<char>>ans(numRows,vector<char>(n,'#'));;
        
        int i=0;
        int col = 0;
        if(numRows ==1){
            return s;
        }
        while(i<n){
            
            for(int j=0;j<numRows;j++){
                if(i>=n){
                    break;
                }
                ans[j][col] = s[i];
                i++;
            }
            col++;
            
             for(int j=numRows-2;j>=1;j--){
                if(i>=n){
                    break;
                }
                ans[j][col] = s[i];
                i++;
            }
            col++;
           
        }
        string val ="";
       
        for(int i=0;i<numRows;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]!='#'){
                    val+=ans[i][j];
                }
            }
        }
        
        return val;
    }
};