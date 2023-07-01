class Solution {
    
private:
    int mini = INT_MAX;
    
    void findMin(int index , vector<int>&cookies, int len, int k , vector<int>&val){
        
        if(index == cookies.size()){
            
            int maxi = INT_MIN;
            
            for(int i = 0; i < k; i++){
                
                maxi = max(maxi, val[i]);
            }
            
            mini = min(mini, maxi);
            return;
        }
        
        for(int i = 0; i < k; i++){
            
   
            val[i] = val[i] + cookies[index];
            findMin(index+1, cookies, len, k, val);
            val[i] = val[i] - cookies[index];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        
        int len = cookies.size();
        
        vector<int>val(k, 0);
        
         findMin(0, cookies, len, k, val);
        
        return mini;
    }
};