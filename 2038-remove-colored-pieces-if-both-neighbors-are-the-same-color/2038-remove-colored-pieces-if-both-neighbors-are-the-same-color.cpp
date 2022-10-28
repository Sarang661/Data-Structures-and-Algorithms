class Solution {
public:
    bool winnerOfGame(string colors) {
        int numAlice = 0;
        int numBob = 0;
        
        int total_size = colors.size();
        int curr = 0;
        
        int index = 0;
        while(index<total_size){
            curr = 0;
            while(index<total_size && colors[index] == 'A'){
                curr++;
                index++;
            }
            
            numAlice+=max(0,(curr-2));
            curr = 0;
            
              while(index<total_size && colors[index] == 'B'){
                curr++;
                index++;
            }
            
            numBob+=max(0,(curr-2));
        }
        
        if(numAlice==numBob){
            return false;
        }
        if(numAlice>numBob){
            return true;
        }
        return false;
    }
};