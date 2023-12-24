class Solution {
public:
    int maxScore(string s) {
        
        int numOnes = 0;
        int numZeros =0;
        
        for(int index = 0; index < s.size(); index++){
            
            if(s[index] == '0'){
                numZeros++;
            }
            else{
                
                numOnes++;
            }
        }
        
        
        int maxi = 0;
        int curr = 0;
        
        for(int index = 0; index < s.size()-1; index++){
            
            if(s[index] == '0'){
                
                curr++;
            }
            else{
                
                numOnes--;
            }
            
             maxi = max(maxi, curr + numOnes);
        }
        
        
        return maxi;
    }
};