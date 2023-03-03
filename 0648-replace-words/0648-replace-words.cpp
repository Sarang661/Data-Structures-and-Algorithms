class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        vector<string>ans;
        
        set<string>st;
        
        int len = dictionary.size();
        
        for(int index = 0; index < len; index++){
            
            st.insert(dictionary[index]);
        }
        
        int index = 0;
        
        while(index < sentence.size()){
            
            string temp = "";
            int start = index;
            bool flag = true;
            
            while(index < sentence.size() && sentence[index] != ' '){
                
                temp+=sentence[index];
                
                if(st.find(temp)!=st.end()){
                    ans.push_back(temp);
                    flag = false;
                    break;
                }
                index++;
            }
            
            if(flag){
                ans.push_back(sentence.substr(start, index-start));
                
            }
            
            while(index <sentence.size() && sentence[index]!=' '){
                index++;
            }
            index++;
            
        }
        
        string val = "";
        
        for(int i = 0; i < ans.size(); i++){
            val+=ans[i];
            
            if(i<ans.size()-1){
                val+=" ";
            }
        }
        
        return val;
    }
};