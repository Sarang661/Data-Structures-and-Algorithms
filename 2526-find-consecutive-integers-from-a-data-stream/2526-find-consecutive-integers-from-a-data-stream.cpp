class DataStream {
    int index =0;
    int val = 0;
    int s = 0;
    vector<int>v;
public:
    DataStream(int value, int k) {
        s= k;
        val = value;
    }
    
    bool consec(int num) {
        
        v.push_back(num);
        // cout<<v.size()<<"\n";
        if(v.size()==1 && num==val && s==1){
            return true;
        }
        else if(v.size()>1){
            int curr = v.size();
            
            if(num!= v[curr-2]){
                index = v.size()-1;
            }
            
            // cout<<(v.size()-index)<<"\n";
            int h = (v.size()-index);
            if(num==val){
                return (h>=s);
            }
        }
        
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */