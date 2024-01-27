### Graph qns

#### Q1. Flood fill (DFS)

Link: https://leetcode.com/problems/flood-fill/description/

```CPP
class Solution {
public:
    void dfs(vector<vector<int>>& image,int currRow,int currCol,int initialColor,int newColor){
        int n=image.size();
        int m=image[0].size();
        if(currRow<0 || currCol<0 || currRow>=n || currCol>m || image[currRow][currCol]!=initialColor || initialColor==newColor){
            return;
        }
        image[currRow][currCol]=newColor;
        dfs(image,currRow+1,currCol,initialColor,newColor);
        dfs(image,currRow,currCol+1,initialColor,newColor);
        dfs(image,currRow-1,currCol,initialColor,newColor);
        dfs(image,currRow,currCol-1,initialColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};
```

```
class Solution {
public:
    void dfs(vector<vector<int>>& image,int currRow,int currCol,int initialColor,int newColor){
        int n=image.size();
        int m=image[0].size();
        if(currRow<0 || currCol<0 || currRow>=n || currCol>m || image[currRow][currCol]!=initialColor || initialColor==newColor){
            return;
        }
        image[currRow][currCol]=newColor;
        dfs(image,currRow+1,currCol,initialColor,newColor);
        dfs(image,currRow,currCol+1,initialColor,newColor);
        dfs(image,currRow-1,currCol,initialColor,newColor);
        dfs(image,currRow,currCol-1,initialColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};
```

#### Q2. Find center of star graph

Link: https://leetcode.com/problems/find-center-of-star-graph/description/

```CPP
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> e1=edges[0];
        vector<int> e2=edges[1];
        // if(e1[0]==e2[0]) return e1[0];
        // if(e1[0]==e2[1]) return e1[0];
        // if(e1[1]==e2[0]) return e1[1];
        // if(e1[1]==e2[1]) return e1[1];

        int ans=(e1[0]==e2[0] || e1[0]==e2[1])?e1[0]:e1[1];
       return ans;
    }
};
```

#### Q3. Keys and rooms (BFS/DFS)

Link: https://leetcode.com/problems/keys-and-rooms/description/

```CPP
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int nbr:rooms[curr]){
                if(visited.count(nbr)==0){
                    q.push(nbr);
                    visited.insert(nbr);
                }
            }

        }
        return visited.size()==rooms.size();

    }
};
```

#### Q4. Clone Graph

LInk: https://leetcode.com/problems/clone-graph/description/

```CPP
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* start,unordered_map<Node*,Node*> &m){
        Node* new_node=new Node(start->val);
        m[start]=new_node;
        //visit all the neighours
        for(auto &nbr:start->neighbors){
            //if visited
            if(m.find(nbr)!=m.end()) {
                new_node->neighbors.push_back(m[nbr]);
            }
            else{
                dfs(nbr,m);
                new_node->neighbors.push_back(m[nbr]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> m;
        dfs(node,m);
        return m[node];
    }
};
```

```CPP
class Solution {
public:

    void dfs(Node* actual,Node* clone){
        for(auto nbr:actual->neighbors){
            if(!nodeRegister[nbr->val]){
                Node* newNode=new Node(nbr->val);
                nodeRegister[newNode->val]=newNode;
                clone->neighbors.push_back(newNode);
                dfs(nbr,newNode);
            }else{
                clone->neighbors.push_back(nodeRegister[nbr->val]);
            }
        }
    }


    vector<Node*> nodeRegister;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node *clone = new Node(node->val);
        nodeRegister.resize(110);
        nodeRegister[clone->val]=clone;
        dfs(node,clone);
        return clone;
    }
    // void dfs(Node* start,unordered_map<Node*,Node*> &m){
    //     Node* new_node=new Node(start->val);
    //     m[start]=new_node;
    //     //visit all the neighours
    //     for(auto &nbr:start->neighbors){
    //         //if visited
    //         if(m.find(nbr)!=m.end()) {
    //             new_node->neighbors.push_back(m[nbr]);
    //         }
    //         else{
    //             dfs(nbr,m);
    //             new_node->neighbors.push_back(m[nbr]);
    //         }
    //     }
    // }
    // Node* cloneGraph(Node* node) {
    //     if(node==NULL) return NULL;
    //     unordered_map<Node*,Node*> m;
    //     dfs(node,m);
    //     return m[node];
    // }
};
```

#### Qn 5: Coloring a border

Link: https://leetcode.com/problems/coloring-a-border/description/
