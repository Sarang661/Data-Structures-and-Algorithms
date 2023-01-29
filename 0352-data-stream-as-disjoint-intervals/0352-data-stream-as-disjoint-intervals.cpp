class SummaryRanges {
    set<int>st;
    
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
      st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        
        vector<vector<int>>ans;
      
        for(auto num:st){
            
            if(ans.size()>0 && (ans[ans.size()-1][1]+1) == num){
                
                ans[ans.size()-1][1] = num;
            }
            else{
                ans.push_back({num,num});
            }
        }
        
        return ans;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */