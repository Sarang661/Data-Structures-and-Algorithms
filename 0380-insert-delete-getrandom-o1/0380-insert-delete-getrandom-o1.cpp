class RandomizedSet {
    set<int>st;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)!=st.end()){
            return false;
        }
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
         if(st.find(val)==st.end()){
            return false;
        }
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand()%st.size();
        int in = 0;
        for(auto x:st){
            if(in==idx){
                return x;
            }
            in++;
        }
        
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */