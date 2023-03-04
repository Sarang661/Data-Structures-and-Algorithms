#define ll long long int

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        ll ans = 0;
        ll n = nums.size();
        ll start = 0;
        bool minStart = false;
        bool maxStart = false;
        ll minIndex = 0;
        ll maxIndex = 0;
        
        for(int index = 0; index < n; index++){
            
            ll curr = nums[index];
            
            if(curr < minK || curr > maxK){
                
                start = index+1;
                minStart = false;
                maxStart = false;
            }
            
            if(curr == minK){
                minIndex = index;
                minStart = true;
            }
            
            if(curr == maxK){
                maxIndex = index;
                maxStart = true;
            }
            
            if(minStart && maxStart){
                
                ans += (min(minIndex, maxIndex)-start+1);
            }
        }
        
        return ans;
    }
};