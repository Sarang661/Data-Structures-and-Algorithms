class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int>maxElement;
        
        int len = piles.size();
        int ans = 0;
        
        for(int index = 0; index < len; index++){
            
            maxElement.push(piles[index]);
        }
        
        while(k--){
            
            int currNum = maxElement.top();
            
            currNum = currNum - currNum / 2;
            
            maxElement.pop();
            maxElement.push(currNum);
        }
        
        while(!maxElement.empty()){
            
            ans+=maxElement.top();
            maxElement.pop();
        }
        
        return ans;
    }
};