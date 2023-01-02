class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int len = word.size();
        
        int prev = 0;
        
    stringstream s(word);
        string curr;
        
        while(s>>curr){
            
            int currLen = 0;
            
            for(int index = 0; index < curr.size(); index++){
                
                if(isupper(curr[index])){
                    currLen ++;
                }
            }
            
            if(isupper(curr[0])){
                
                if(currLen > 1 && currLen <curr.size()){
                    return false;
                }
                
            }
            else if(currLen>0){
                
                return false;
            }
        }
        
        return true;
    }
};