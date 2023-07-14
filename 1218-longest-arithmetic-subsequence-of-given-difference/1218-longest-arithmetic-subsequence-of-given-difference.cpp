class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        map<int,int>longestSub;
        int ans  = 0;
        
        for(int index = 0; index < arr.size(); index++){
            
            int curr = arr[index] - difference;
            
            if(longestSub.find(curr)!= longestSub.end()){
                
                longestSub[arr[index]] =  longestSub[curr]+1;
                    
                    
            }
            else{
                 longestSub[arr[index]]  = 1;
            }
            ans = max(ans, longestSub[arr[index]]);
        }
        
        return ans;
    }
};