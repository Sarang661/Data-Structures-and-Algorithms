class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int minFlips  = 0;
        
        while(c > 0){
            
            int a1 = a&1;
            int b1 = b&1;
            int c1 = c&1;
            
            if((c1 != 0)  &&  (a1 == 0) && (b1 == 0)){
              
                minFlips++;
            }
            else if((c1 == 0) && ((a1== 1) || (b1 == 1))){
                minFlips++;
                
                if(a1 == 1 && b1 == 1){
                    minFlips++;
                }
            }
            
            a = a/2;
            b = b/2;
            c = c/2;
        }
        
        while(a > 0){
            if(a&1){
                minFlips++;
            }
            a = a/2;
        }
        
          while(b > 0){
            if(b&1){
                minFlips++;
            }
            b = b/2;
        }
        
        return minFlips;
    }
};