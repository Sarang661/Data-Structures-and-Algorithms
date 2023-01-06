class Solution {
public:
    string getHint(string secret, string guess) {
        
        int numBulls = 0;
        int numCows = 0;
        
        int len = secret.size();
        vector<int>freq(10, 0);
        
        for(int index = 0; index < len; index++){
            
            if(secret[index] == guess[index]){
                numBulls++;
            }
            
            freq[guess[index]-'0']++;
            
        }
        
        for(int index = 0; index < len; index++){
            
            if( freq[secret[index]-'0'] > 0){
                
            numCows +=1;
                
            }
            freq[secret[index]-'0']--;
        }
        
       numCows = numCows - numBulls ;
        
        string ans = to_string(numBulls) + "A" + to_string(numCows) + "B";
        
        return ans;
    }
};