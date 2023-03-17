class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        
        int ans = 0;
        bool flag = true;
        
        for(auto x:freq){
            if(x.second%2==0){
                ans+=x.second;
            }
            else if(flag){
                ans+=x.second;
                flag = false;
            }
            else{
                ans+=(x.second-1);
            }
        }
        
        return ans;
    }
};