class Solution {
    
private:
    
    int bs(vector<int>&nums, int val){
        
        int l = 0;
        int h = nums.size()-1;
        int ans = -1;
        while(l<=h){
            
            int m = l + (h-l)/2;
            if(nums[m]>val){
                h = m-1;
            }
            else{
                ans = m;
                l = m+1;
            }
        }
        
        return ans;
    }
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        vector<int>prefixSum;
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
          
        }
        
        vector<int>ans;
       
        for(int j=0;j<queries.size();j++){
            
            int val = queries[j];
            
            int index = bs(prefixSum, val);
            
            if(index>=0){
                ans.push_back(index+1);
            }
            else{
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};