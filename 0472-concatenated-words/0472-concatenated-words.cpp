   class Node{
        public:
        string s = "";
        Node*links[26];
    };

class Solution {
    
 
    
    void insert(Node* root, string &word){
        Node*curr = root;
        
        int len = word.size();
        
        for(int i=0;i<len;i++){
            char c = word[i];
            if(curr->links[c-'a']==NULL){
                curr->links[c-'a'] = new Node();
            }
            curr = curr->links[c-'a'];
        }
        curr->s = word;
     
    }
    
    void search1(Node*curr, Node*temp, Node*root, vector<string>&ans){
        
        if((curr->s).size()>0 && (temp->s).size()>0){
            ans.push_back(curr->s);
            
            search1(curr,root, root,ans);
        }
        
        if((temp->s).size()>0){
            search1(curr,root,root,ans);
        }
        for(int i=0;i<26;i++){
            if(curr->links[i]!=NULL && temp->links[i]!=NULL){
                
                search1(curr->links[i],temp->links[i],root, ans);
            }
        }
    }
    void search(Node*curr, Node*root, vector<string>&ans){
        
        if((curr->s).size()>0){
           
            search1(curr,root, root,ans);
        }
        for(int i=0;i<26;i++){
            if(curr->links[i]!=NULL){
                search(curr->links[i],root,ans);
            }
        }
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        Node*root = new Node();
        
        for(int i=0;i<words.size();i++){
        insert(root, words[i]);
        }
        
        vector<string>ans;
        
  set<string>st;
        search(root, root, ans);
        
        for(int i=0;i<ans.size();i++){
            st.insert(ans[i]);
        }
        vector<string>v;
        for(auto x:st){
            v.push_back(x);
        }
        
        
        return v;
        
    }
    
};