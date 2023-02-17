class Solution {
public:
    vector<int> getRow(int rowIndex) {
                vector<vector<int>>pascalTriangle(rowIndex+1);
        
        for(int i=0;i<=rowIndex;i++){
            
            vector<int>curr;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    curr.push_back(1);
                }
                else{
                    curr.push_back(pascalTriangle[i-1][j]+pascalTriangle[i-1][j-1]);
                }
            }
            pascalTriangle[i]=curr;
        }
        return pascalTriangle[rowIndex];
    }
};