class Solution {
public:
    int reverse(int x) {
        
        string s = to_string(x);
        
        int startIndex = 0;
        int endIndex = s.size()-1;
        
        if(s[startIndex]=='-'){
            startIndex++;
        }
        
        int curr = startIndex;
        
        while(startIndex < endIndex){
            
            swap(s[startIndex], s[endIndex]);
            startIndex++;
            endIndex--;
        }
        
        long long num = stoll(s);
        
        if(num>INT_MAX || num < INT_MIN){
            return 0;
        }
        
        return num;
    }
};