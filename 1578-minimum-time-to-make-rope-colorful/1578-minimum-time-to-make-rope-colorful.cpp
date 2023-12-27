// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int  n = colors.size();
       
        int maxi = INT_MIN;
        int currSum = 0;
        int totalVal = 0;
        for(int i=0;i<n;i++){
            maxi = INT_MIN;
            while((i<n-1 && colors[i]==colors[i+1])){
                maxi = max(neededTime[i],maxi);
                   currSum += neededTime[i];
                i++;
            }
          
                   currSum += neededTime[i];
                  maxi=    max(neededTime[i],   maxi);
                totalVal += currSum - maxi;
               
                
            
             currSum = 0;
           
        }
        return totalVal;
    }
};