class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        
        while(j<n){
            if(s[j]==' ' || j==n-1){
                int k = j;
                if(s[j]==' '){
                j--;
                }
                while(i<j){
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
                j=k+1;
                i=k+1;
            }
            j++;
        }
        return s;
    }
};