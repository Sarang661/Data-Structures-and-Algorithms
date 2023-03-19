class Node{
    
    public:
    Node*links[26];
    bool flag = false;
};

class Trie{
    
    public:
    Node* root1;
    Trie(){
        
        root1 = new Node();
    }
    void insert(string &word){
        
        Node * root = root1;
        for(int index = 0; index < word.size(); index++){
            
            if(root->links[word[index]-'a'] == NULL){
                root->links[word[index]-'a'] = new Node();
            }
            
            root = root->links[word[index]-'a'];
        }
        
        root->flag = true;
    }
    
    bool find(string &word, int index, Node*root){
        
        if(index == word.size() && root->flag == true){
            return true;
        }
        
        if(index == word.size()){
            return false;
        }
    
        if(word[index] == '.'){
            
            for(int i = 0; i < 26; i++){
                if(root->links[i]!=NULL && find(word, index+1, root->links[i])){
                    return true;
                }
            }
        }
           else if(root->links[word[index]-'a']!=NULL){
               
                return find(word, index+1, root->links[word[index]-'a']);
            }
            return false;
        }

};

class WordDictionary {
    
    Trie t;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        
        return t.find(word,0,t.root1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */