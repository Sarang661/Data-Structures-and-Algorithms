class Solution {
    
private:
    
    bool poss(vector<int>nums, long long target){
        
        long long prev = 0;
        long long curr= 0;
        
        for(int index = nums.size()-1; index >= 0; index--){
            
            curr = nums[index] + prev;
             prev = max((long long)0, curr - target);
        }
        
        cout<<target<<"\n";
        return (curr - target)<=0;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        
        while(low < high){
            
            int mid = low + (high-low)/2;
            
            if(poss(nums, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};