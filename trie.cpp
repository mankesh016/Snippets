
// trie

struct Node{
    Node* ch[26];
    bool isEnd;
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(auto c: word){
            int t = c-'a';
            if(temp->ch[t] == NULL){
                temp->ch[t] = new Node();
            }
            temp= temp->ch[t];
        }
        temp->isEnd= true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(auto c: word){
            int t = c-'a';
            if(temp->ch[t] == NULL) return false;
            temp= temp->ch[t];
        }
        return (temp->isEnd);
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(auto c: prefix){
            int t = c-'a';
            if(temp->ch[t] == NULL) return false;
            temp= temp->ch[t];
        }
        return true;
    }
};
