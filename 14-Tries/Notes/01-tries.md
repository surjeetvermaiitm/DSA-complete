#### Q1. Implement Tries I

Link:https://leetcode.com/problems/implement-trie-prefix-tree/description/

```CPP
class Node{
    public:
        char data;
        bool terminal;
        unordered_map<char,Node*> children;
        Node(char data){
            this->data=data;
            this->terminal=false;
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
            }else{
                Node* child=new Node(ch);
                curr->children[ch]=child;
                curr=child;
            }
        }
        curr->makeTerminal();

    }

    bool search(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(curr->children.count(ch)){
                curr=curr->children[ch];
            }else{
                //we don't have a char
                return false;
            }
        }
        return curr->isTerminal();

    }

    bool startsWith(string prefix) {
        Node* curr=root;
        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
            if(curr->children.count(ch)){
                curr=curr->children[ch];
            }else{
                //we don't have a char
                return false;
            }
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
```

#### Q2. Implement Tries 2

Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

```CPP
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
```

#### Qn3. Maximum XOR of two numbers in an array

Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

```CPP
class Node{
    public:
        Node* left;
        Node* right;
        Node(){
            this->left=this->right=NULL;
        }

};



class Solution {
public:
    int maxXorPair(Node* head,int value){
        int curr_xor=0;
        Node* curr=head;
        for(int i=31;i>=0;i--){
            int bit=(value>>i) & 1;
            if(bit==0){
                if(curr->right!=NULL){
                    curr=curr->right;
                    curr_xor+=(1<<i);
                }else{
                    curr=curr->left;
                }

            }else{
                if(curr->left!=NULL){
                    curr=curr->left;
                    curr_xor+=(1<<i);
                }else{
                    curr=curr->right;
                }

            }
        }
        return curr_xor;
    }
    void insert(Node* head,int value){
        Node* curr=head;
        for(int i=31;i>=0;i--){
            int bit=(value>>i) &1;
            if(bit==0){
                if(curr->left==NULL){
                    curr->left=new Node();
                }
                curr=curr->left;
            }else{
                if(curr->right==NULL){
                    curr->right=new Node();
                }
                curr=curr->right;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        Node* head=new Node();
        insert(head,nums[0]);
        int ans=0;
        for(int i=1;i<nums.size();i++){
            ans=max(ans,maxXorPair(head,nums[i]));
            insert(head,nums[i]);
        }
        return ans;
    }
};

```
