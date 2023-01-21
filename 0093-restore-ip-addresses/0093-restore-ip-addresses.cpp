class Solution {

vector<string>ans;

string res;
   
bool isValid(string &s){
    
    int num = stoi(s);
    
    if(num>255 || (s[0] == '0' && s.size()>1)){
        return false;
    }
    
    return true;
}
void findAllValid(string &s, int index, int part){
    
    if(part == 4 && s.size() == index){
        ans.push_back(res);
        return;
    }
    
    for(int j = index; j < s.size(); j++){
        
        string curr = s.substr(index, j-index+1);
        
        if( j-index+1 < 4 && isValid(curr) && part<4){
            
            part++;
            
             res += curr;
            
            if(part<4){
                res+=".";
            }
            
            findAllValid(s, j+1, part);
            
            if(part < 4){
                res.pop_back();
            }
            part--;
            
            for(int k=0;k<curr.size();k++){
                res.pop_back();
            }
        }
    }
}
public:
    vector<string> restoreIpAddresses(string s) {
        
        findAllValid(s,0, 0);
        return ans;
    }
};