class BrowserHistory {
    
    vector<string>history;
    
    int curr = 0;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        
        int len = history.size() - curr - 1;
        
        while(len--){
            history.pop_back();
        }
        
        history.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        
        int mini = min(steps, (int)curr);

        curr = curr - mini;
       
        return history[curr];
    }
    
    string forward(int steps) {
        
        int mini = min(steps,  (int)history.size()-curr-1);
        curr = curr + mini;
        
        return history[curr];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */