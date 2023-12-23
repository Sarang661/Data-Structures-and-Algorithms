class Solution {
public:
    bool isPathCrossing(string path) {
        
        int x = 0;
        int y = 0;
        
        set<pair<int, int>>st;
        
        st.insert({0,0});
        for(int index = 0; index < path.size(); index++){
            
            if(path[index] == 'N'){
                
                y++;
            }
            else if(path[index] == 'S'){
                
                y--;
            }
            else if(path[index] == 'E'){
                
                x++;
            }
            else{
                
                x--;
            }
            
            if(st.find({x,y})!= st.end()){
                
                return true;
            }
            st.insert({x,y});
        }
        
        
        return false;
    }
};