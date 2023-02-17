class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int remain = 1;
        int len = digits.size();
        
        for(int index = len -1; index >= 0; index--){
            
            int total = remain + digits[index];
            int curr = total%10;
            remain = total/10;
            
            digits[index] = curr;
            
        }
        
        if(remain>0){
            digits.insert(digits.begin(), remain);
        }
        
        return digits;
    }
};