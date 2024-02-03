//Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Node{
    public:
        char data;
        bool terminal;
        unordered_map<char,Node*> children;
        int countWordsEndingHere;
        int countWordsStarting;
        Node(char data){
            this->data=data;
            this->terminal=false;
            this->countWordsEndingHere=this->countWordsStarting=0;
        }
        void makeTerminal(){
            this->terminal=true;
        }
        bool isTerminal(){
            return this->terminal==true;
        }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node('\0');
    }

    void insert(string word) {
        Node *curr=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];//curr char to be check
            if(curr->children.count(ch)){
                curr=curr->children[ch];
                curr->countWordsStarting++;
            }else{
                Node* child=new Node(ch);
                curr->children[ch]=child;
                curr=curr->children[ch];
                curr->countWordsStarting++;
            }
        }
        curr->makeTerminal();
        curr->countWordsEndingHere++;

    }

    int countWordsEqualTo(string word){
        Node *curr=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(curr->children.count(ch)){
                curr=curr->children[ch];
            }else{
                return 0;
            }
        }
        return curr->countWordsEndingHere;

    }
    int countWordsStartWith(string prefix){
        Node *curr=root;
        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
            if(curr->children.count(ch)){
                curr=curr->children[ch];
            }else{
                return 0;
            }
        }
        return curr->countWordsStarting;
    }

    void erase(string word){
        Node *curr=root;
        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
            curr=curr->children[ch];
            curr->countWordsStarting--;
        }
        curr->countWordeEndingHere--;
    }


};