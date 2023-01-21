class Solution {

    
            
public:
     string res;
    vector<string>ans;
    
    vector<string> restoreIpAddresses(string s) {
        
        int p = 0;
        findAll(s, 0, 0);
        
        return ans;
    }
   
    
    
    
    void findAll(string &s, int part, int index){
        
     
       if(index == s.size()  && part == 4 ){
            
            ans.push_back(res);
            
            return;
        }
        
        
        for(int j=index ; j < s.size(); j++){
            
      
            
            if( part < 4 && j-index < 3  && validIP(s, index, j)){
                
               
          res.append(s.substr(index, j-index+1));
                 // cout<<res<<" ";
                 part++;
                
                if(part < 4){
                    res.push_back('.');
                }
                
               
                findAll(s, part, j+1);
                
                if(part<4){
                 res.pop_back();
                }
                
                part--;
                
                for(int k=0;k <(j-index+1);k++){
                    res.pop_back();
                }
            }
        }
        
    }

    
    
       bool validIP(string s, int start, int end)
    {
        string temp = s.substr(start, end-start+1);
        int ip = stoll(temp);
        
        if(s[start] == '0' && start != end) return false;
        else if(ip >= 0 && ip <= 255) return true;
        
        return false;
    }
};