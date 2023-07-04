class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int n =nums.size();
        int oneCount =0;
        for(int i=0;i<32;i++){
            oneCount=0;
            for(int j=0;j<n;j++){
                if((nums[j]&(1<<i))){
                    oneCount++;
                }
            }
            if((oneCount%3)){
                ans=ans | (1<<i);
            }
        }
        return ans;
    }
};