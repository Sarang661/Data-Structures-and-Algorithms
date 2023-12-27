class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int maxi = INT_MIN;
        int currSum = 0;
        int ans = 0;
        
        for(int  index = 0; index < colors.size(); index++){
            
            if(index < colors.size() -1 && colors[index] == colors[index+1]){
                
                currSum += neededTime[index];
                maxi = max(maxi,neededTime[index]);
            }
            else{
                
                maxi = max(maxi, neededTime[index]);
                currSum += neededTime[index];
                currSum = currSum - maxi;
                cout<<currSum<<"\n";
                ans = ans + currSum;
                currSum = 0;
                maxi = INT_MIN;
            }
        }
        
        return ans;
    }
};