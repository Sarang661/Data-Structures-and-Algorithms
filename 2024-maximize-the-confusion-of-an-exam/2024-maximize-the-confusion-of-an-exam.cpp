class Solution {
public:
    int maxConsecutiveAnswers(string& s, int k) {
        int n=s.length(),i=0,j=0,cntf=0,cntt=0,len=0;
        while(j<n){
            if(s[j]=='F'){
                cntf++;
                while(cntf>k){
                    if(s[i++]=='F') cntf--;
                }
            }
            len=max(len,j-i+1);
            j++;
        }
        i=j=0;
        while(j<n){
            if(s[j]=='T'){
                cntt++;
                while(cntt>k){
                    if(s[i++]=='T') cntt--;
                }
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};