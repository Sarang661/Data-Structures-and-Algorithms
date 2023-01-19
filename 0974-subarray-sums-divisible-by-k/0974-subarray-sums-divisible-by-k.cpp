class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        map<int,int>remainder;
        
        int len = nums.size();
        int ans = 0;
        remainder[0] = 1;
        int currSum = 0;
        
        for(int index = 0; index < len; index++){
            
           currSum+= nums[index];
            
            int curr = currSum%k;
            if(curr<0){
                curr+=k;
            }
            ans+= remainder[curr];
            remainder[curr]++;
        }
        
        return ans;
    }
};