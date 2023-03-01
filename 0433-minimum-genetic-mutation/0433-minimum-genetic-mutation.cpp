class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        set<string>valid;
        
        int len = bank.size();
        
        for(int index = 0; index < len; index++){
            
            valid.insert(bank[index]);
        }
        
        if(valid.find(endGene) == valid.end()){
            cout<<"hi";
            return -1;
        }
        
        set<string>visited;
        visited.insert(startGene);
        
        queue<pair<string,int>>curr;
        curr.push({startGene, 0});
        
        char diff[4] = {'A', 'C', 'G', 'T'};
        
        while(!curr.empty()){
            
            string val = curr.front().first;
            int steps = curr.front().second;
            
            curr.pop();
            
            if(val == endGene){
                return steps;
            }
            
           string original = val;
            
            for(int index = 0; index < val.size(); index++){
                
               for(int j = 0; j < 4; j++){
                   
                    val[index] = diff[j];
                   
                   if(visited.find(val)==visited.end() && valid.find(val)!=valid.end() ){
                       
                       visited.insert(val);
                       curr.push({val, steps+1});
                   }
                   

               }
                                   val = original;
            }
        }
        
        return -1;
    }
};