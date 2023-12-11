class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int num = arr.size()/4;
        
        int ans = arr[0];
        int currFreq = 1;
        
        for(int index = 1; index < arr.size(); index++){
            
            if(arr[index] == arr[index-1]){
                
                currFreq++;
            }
            else{
                
                currFreq = 1;
            }
            
            if(currFreq > num){
                
                return arr[index];
            }
        }
        
        
        return ans;
    }
};