class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>remainder;
        
        int total_size = nums.size();
        remainder[0] = -1;
        int curr_sum = 0;
        for(int index = 0;index < total_size;index++){
            curr_sum += nums[index];
            if(remainder.find(curr_sum%k)!=remainder.end() && index-remainder[curr_sum%k]>=2){
                return true;
            }
           else if(remainder.find(curr_sum%k)==remainder.end()){
               remainder[curr_sum%k] = index;
           }
        }
        return false;
    }
};