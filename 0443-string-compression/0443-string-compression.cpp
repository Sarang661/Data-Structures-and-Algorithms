class Solution {
public:
    int compress(vector<char>& chars) {
        
        int currLen = 1;
        int ans = 0;
        int len = chars.size();
        int index = 1;
        int curr = 0;
        
        while(index <= len){
            
            while(index < len && chars[index-1] == chars[index]){
                index++;
                currLen++;
            }
            
            
            if(currLen == 1){
                currLen = 1;
                chars[curr] = chars[index-1];
                curr++;
                ans+=1;

            }
            else{
              
            chars[curr] = chars[index-1];
                curr++;
                ans++;
                
                if(currLen>=10){
                     string s = to_string(currLen);
                    for(int j = 0; j < s.size();j++){
                        
                        chars[curr] = s[j];
                        ans++;
                        curr++;
                    }
                  
                }
                else{
                    ans+=1;
                    chars[curr] = (char)(currLen+'0');
                    curr++;
                }
                currLen = 1;
            }
            
            index++;
        }
        
        
        return ans;
    }
};