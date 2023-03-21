class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string>m;
        for(vector<string>temp : k)  m[temp[0]]= temp[1];
        string res = "";
        int n = s.length(),i=0;
        while(i<n){
            if(s[i] != '(') res += s[i++];
            else{
                int j = i+1;
                string temp = "";
                while(j<n && s[j] != ')') 
                    temp+=s[j++];
                if(m.find(temp) != m.end()) res += m[temp];
                else res += '?';
                i = j+1;
            }
        }
        return res;
    }
};