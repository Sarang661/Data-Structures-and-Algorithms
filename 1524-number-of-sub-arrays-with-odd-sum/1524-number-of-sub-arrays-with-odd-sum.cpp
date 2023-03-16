class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int eveSum = 1;
        int oddSum = 0;
        int currSum = 0;
        long long ans = 0;
        long long mod = 1e9 + 7;
        
        for(int index = 0; index < arr.size(); index++){
            
            currSum +=arr[index];
            
            if(currSum%2){
                ans = (ans + eveSum)%mod;
                oddSum++;
            }
            else{
                  ans = (ans + oddSum)%mod;
                eveSum++;
            }
        }
        
        return ans;
    }
};