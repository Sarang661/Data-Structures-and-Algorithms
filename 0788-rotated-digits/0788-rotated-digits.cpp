class Solution {
public:
    int rotatedDigits(int n) {
     
        int ans = 0;
        
        map<int,int>m;
        
        m[2] = 5;
        m[6] = 9;
        m[0] = 0;
        m[1] = 1;
        m[8] = 8;
        m[5] = 2;
        m[9] = 6;
        
        for(int index =1; index <=n ; index++){
            
            if(index == 4 || index == 1 || index == 8 || index == 3 || index == 7){
                continue;
            }
            
            string s = to_string(index);
            bool flag = false;
            for(int j = 0; j < s.size(); j++){
                
                int val = s[j] - '0';
                
                if(val == 3 || val == 4 || val == 7){
                    flag = true;
                    break;
                }
                
                s[j] = (char)(m[val] + '0');
            }
            
            int num = stoi(s);
            
            if(num!=index && flag == false){
              
                ans++;
            }
        }
        
        return ans;
        
    }
};