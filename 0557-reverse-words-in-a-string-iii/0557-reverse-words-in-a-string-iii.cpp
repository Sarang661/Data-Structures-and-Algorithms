class Solution {
public:
    string reverseWords(string s) {
        
        
        int prev = 0;
        
        for(int index = 0; index <= s.size(); index++){
            
            if(s[index] == ' ' || index == (s.size())){
                

                reverse(s.begin()+prev, s.begin()+ index);
                prev = index+1;
            }
        }
        
        return s;
    }
};