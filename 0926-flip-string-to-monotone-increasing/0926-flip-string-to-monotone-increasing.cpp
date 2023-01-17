class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros = 0;
        int ones = 0;
        int totalOnes = 0;
       
        int n = s.size();
        int mini = INT_MAX;
        
         for(int i=0;i<n;i++){
            if(s[i]=='1'){
                totalOnes++;
            }
        }
        
        mini = min(mini, n-totalOnes);
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='1'){
                ones++;
                totalOnes--;
            }
            
            int zeros = n - i -1 - totalOnes;
            mini = min(mini, ones+zeros);
        }
        
        return mini;
    }
};