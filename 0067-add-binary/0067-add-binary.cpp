class Solution {
public:
    string addBinary(string a, string b) {
        
        int curr1 = 0;
        int curr2 = 0;
        int remain = 0;
        string ans = "";
        int i = a.size() -1;
        int j = b.size() - 1;
        
        while(i>=0 || j>=0){
            if(i>=0){
                curr1 = a[i]-'0';
                i--;
            }
            else{
                curr1 = 0;
            }
              if(j>=0){
                curr2 = b[j]-'0';
                j--;
            }
            else{
                curr2 = 0;
            }
            
            int total = curr1 + curr2 + remain;
            if(total == 3){
                ans+="1";
                remain = 1;
            }
            else if(total == 2){
                ans+="0";
                remain = 1;
            }
            else {
                ans+=to_string(total);
                remain = 0;
            }
            
        }
        
        if(remain > 0){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};