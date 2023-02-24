class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n =nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
            nums[i]=nums[i]*2;
            }
        }
        int mini=INT_MAX;
        int maxi =INT_MIN;
        int res =INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi =max(maxi,nums[i]);
        }
        res= min(res,maxi-mini);
        priority_queue<int>q;
        for(int i=0;i<n;i++){
            q.push(nums[i]);
        }
        while(res>0){
            maxi= q.top();
            res=min(res,maxi-mini);
            if(maxi%2==1){
                break;
            }
            q.pop();
            maxi=maxi/2;
            q.push(maxi);
            mini=min(mini,maxi);
        }
        return res;
    }
};