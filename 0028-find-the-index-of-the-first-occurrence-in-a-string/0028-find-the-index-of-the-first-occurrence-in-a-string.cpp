class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int len = needle.size();
        
        vector<int>lps(len, 0);
        
        int start = 0;
        int end = 1;
        
        while(end < len){
            
            if(needle[start] == needle[end]){
                
                lps[end] = 1 + start;
                start++;
                end++;
            }
            else{
                
                while(start>0 && needle[start] != needle[end]){
                    
                    start = lps[start-1];
                }
                
                if(needle[start] == needle[end]){
                
                lps[end] = 1 + start;
                start++;
                end++;
                    
                }
                else{
                    lps[end]  = 0;
                    end++;
                }
                     
            }
        }
        
        int len2= haystack.size();
        
        start = 0;
        end = 0;
        
       
        while(start< len && end < len2){
            
            if(needle[start]== haystack[end]){
                start++;
                end++;
            }
            else{
                
                while(start > 0 && needle[start]!=haystack[end]){
                    
                    start = lps[start-1];
                }
                
                if(needle[start] != haystack[end]){
                    end++;
                }
                else{
                            start++;
                     end++;
                }
                
            }
        }
        
        if(start == len){
            return end-len;
        }
        
        return -1;
        
    }
};