class Solution {
public:
    int numberOfWays(string corridor) {
        
       long numWays = 1;
 
        long mod = 1e9 + 7;

        
          vector<int>seatIndex;
        
        for(int index = 0; index < corridor.size(); index++){
            
            if(corridor[index] == 'S'){
          
                seatIndex.push_back(index);
            }
            
        }
        
        if(seatIndex.size()== 0 || seatIndex.size()%2 != 0){
            
            return 0;
        }
   
        
        for(int index = 2; index < seatIndex.size(); index+=2){
            
            long diff = seatIndex[index]- seatIndex[index-1];
          
            numWays = (numWays*diff)%mod;
        }
        
        return numWays;
        
    }
};