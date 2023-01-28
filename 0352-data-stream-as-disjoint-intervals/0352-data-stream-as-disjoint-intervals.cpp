class SummaryRanges {
    vector<int>v;
    set<int>st;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(st.find(value)==st.end()){
                   st.insert(value);
        v.push_back(value);
        sort(v.begin(),v.end());
        }
    
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        
        int start = v[0];
        int end = v[0];
        
        for(int i=1;i<v.size();i++){
            if(v[i] == end+1){
                end=v[i];
                  if(i==(v.size()-1)){
                    ans.push_back({start,end});
                }
            }
            else{
                ans.push_back({start,end});
                start = v[i];
                end = v[i];
                if(i==(v.size()-1)){
                    ans.push_back({start,end});
                }
            }
        }
        
        if(ans.size()==0){
            return {{start,end}};
        }
        else{
            return ans;
        }
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */