class Node{
    public:
    Node*links[26];
    bool flag = false;

};

bool containsKey(char ch,Node*root){
    
    return root->links[ch-'a']!=NULL;
}
void setFlag(Node*root){
   root->flag = true;
}
class Trie {
private:
    Node*root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*node = root;
        int len = word.size();
        for(int i=0;i<len;i++){
            char curr = word[i];
            if(!containsKey(word[i],node)){
                node->links[curr-'a']= new Node();
            }
          node = node->links[curr-'a'];
        }
        setFlag(node);
        
    }
    
    bool search(string word) {
           Node*node = root;
        int len = word.size();
        for(int i=0;i<len;i++){
            char curr = word[i];
            if(!containsKey(word[i],node)){
                return false;
            }
            node = node->links[curr-'a'];
        }
       return node->flag;
    }
    
    bool startsWith(string prefix) {
          Node*node = root;
        int len =  prefix.size();
        for(int i=0;i<len;i++){
            char curr = prefix[i];
            if(!containsKey( prefix[i],node)){
                return false;
            }
            node = node->links[curr-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */