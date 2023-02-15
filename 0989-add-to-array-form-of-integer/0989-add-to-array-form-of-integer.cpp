class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int len = num.size();
        int remain = 0;
        int curr = 0;
        
        
        for(int index = len -1; index>=0; index--){
            int val = num[index] + remain + k%10;
            k = k /10;
            
            if(val>= 10){
                num[index] = val%10;
                remain = val/10;
            }
            else{
                remain = 0;
                num[index] = val;
            }
        }
        
        while(k>0){
            int val = k%10 + remain;
            k = k/10;
            if(val>= 10){
                num.insert(num.begin(), val%10);
                remain = val/10;
            }
            else{
                remain = 0;
                num.insert(num.begin(), val);
            }
        }
        
        if(remain>0){
            num.insert(num.begin(), remain);
        }
        
        return num;
    }
};