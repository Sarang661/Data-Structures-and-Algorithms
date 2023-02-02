class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>v(26,0);
        int curr = 0;
        
        for(int i=0;i<order.size();i++){
            v[order[i]-'a'] = curr;
            curr++;
        }
        
        bool flag = false;
        
        for(int i=0;i<words.size()-1;i++){
           
            int len1 = words[i].size();
            int len2 = words[i+1].size();
            flag = false;
            int k = 0;
            int j = 0;
            
            while(k<len1 && j<len2){
                
                 if(v[words[i][k]-'a'] < v[words[i+1][j]-'a']){
                     flag = true;
                     
                   break;
                }
                
                if(v[words[i][k]-'a'] > v[words[i+1][j]-'a']){
                    return false;
                }
                k++;
                j++;
            }
            
            if(len1 > len2 && flag == false){
                
                return false;
            }
        }
        return true;
    }
};