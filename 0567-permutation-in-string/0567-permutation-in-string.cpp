class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size() < s1.size()){
            
            return false;
        }
        
        int num = 0;
    vector<int>v1(26,0);
    vector<int>v2(26,0);
        
        for(int i=0;i<s1.size();i++){
          v1[s1[i]-'a']++;
        }
     
        int j = 0;
    
        while(j<s1.size()){
            v2[s2[j]-'a']++;
            j++;
        }
        
        if(v1 == v2){
            return true;
        }
        
        int i = 0;
                        
        while(j<s2.size()){
          v2[s2[j]-'a']++;     
            v2[s2[i]-'a']--;
      
            if(v1==v2){
            return true;
            }
            i++;
            j++;
        }
        
        return false;
    }
};