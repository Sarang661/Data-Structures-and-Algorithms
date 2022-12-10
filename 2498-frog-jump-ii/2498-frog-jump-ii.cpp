class Solution {
private:
    bool poss(int val,vector<int>v){
        
        int n = v.size();
        int prev = 0;
        bool flag = false;
        for(int i=1;i<n;i++){
            if((v[i]-prev)<=val){
                flag = true;
              
            }
               else{
                    // cout<<i<<" ";
                   if(flag == false){
                       return false;
                   }
                   
                   prev = v[i-1];
                   
                   if((i-1)!= 0 && (i-1)!=(n-1)){
                            
                   v[i-1] = -1;
                   }
            
               }
               
       }
        
        prev = v[n-1];
        
  
             for(int i=n-1;i>=0;i--){
            if(v[i]!= -1 && abs(v[i]-prev)<=val){
               
              prev = v[i];
            }
              
       }
        
        return prev == 0;
        
    }
public:
    int maxJump(vector<int>& s) {
        
        int n = s.size();
        int low = 0;
        
        int high = s[n-1] - s[0];
        int ans = -1;
        
        while(low<high){
            int m = low + (high-low)/2;
            // cout<<m<<" ";
            if(poss(m,s)){
               
                ans = m;
                high = m;
                
            }
            else{
                 low = m+1;
            }
        }
        
        return low;
    }
};