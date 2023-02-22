class Solution {
public:
    int countVowelStrings(int n) {
        
        if(n==1){
            return 5;
        }
        
        vector<int>freq(5,1);
        
        int ans = 5;
        
        for(int index = 2; index <= n; index++){
            
            ans = 0;
            for(int i = 0; i< 5; i++){
                
                int curr = 0;
                
                for(int j = i; j < 5;j++){
                    curr += freq[j];
                }
                
                freq[i] = curr;
                ans+=curr;
            }
        }
        
        return ans;
    }
};