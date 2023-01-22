class Solution {
    
    bool isPalindrome(string &s){
        
        int i=0;
        int j = s.size()-1;
        
        while(i<j){
            if(s[i]!= s[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    void findAll(int index, vector<vector<string>>&ans, vector<string>&v, string &s){
        
        
        if(index==s.size()){
            ans.push_back(v);
            return;
        }
        
        for(int j = index; j<s.size();j++){
            
            string curr = s.substr(index, j-index+1);
            
            if(isPalindrome(curr)){
            v.push_back(curr);
            findAll(j+1, ans, v,s);
            v.pop_back();
            }
        }
        

    }
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>ans;
        vector<string>v;
        
        findAll(0,ans, v, s);
        
        return ans;
    }
};