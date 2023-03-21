class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long len = nums.size();
        
        long long ans = 0;
        long long start = 0;
        long long end = 0;
        
        while(end < len){
            

            while(end < len && nums[end]==0){
                end++;
            }
            
            long long val = end - start;
            ans +=val*(val+1)/2;
            
            end++;
            start = end;
        }
        
        return ans;
    }
};