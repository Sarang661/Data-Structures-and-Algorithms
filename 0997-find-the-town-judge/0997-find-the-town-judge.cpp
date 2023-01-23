class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        map<int,int>m;
        
        int len = trust.size();
        
        if(len == 0 && n==1){
            return n;
        }
        for(int index= 0;index < len; index++){
            m[trust[index][1]]++;
        }
        
        for(int i=0;i<len;i++){
            if(m.find(trust[i][0])!=m.end()){
                m.erase(trust[i][0]);
            }
        }
        
        for(auto x:m){
            if(x.second == n-1){
                return x.first;
            }
        }
        
        return -1;
    }
};