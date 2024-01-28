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

```CPP
class Solution {
public:
    vector<pair<int,int>> internal;
    void dfs(vector<vector<int>>& grid, int row, int col, int color,int initialColor){
        int m=grid.size();
        int n=grid[0].size();
        if(row>m-1 || col>n-1 || row<0 || col<0 || grid[row][col]!=initialColor){
            return;
        }


        grid[row][col]=-color;
        dfs(grid,row+1,col,color,initialColor);
        dfs(grid,row,col+1,color,initialColor);
        dfs(grid,row-1,col,color,initialColor);
        dfs(grid,row,col-1,color,initialColor);

        //below code will be executed while coming back

        if(!(row==0 || col==0 || row==m-1 || col==n-1 || grid[row+1][col]!=-color || grid[row-1][col]!=-color || grid[row][col+1]!=-color || grid[row][col-1]!=-color)){
            internal.push_back({row,col});
        }

    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color ) {
        int initialColor=grid[row][col];
        if(initialColor==color) return grid;
        int m=grid.size();
        int n=grid[0].size();

        dfs(grid,row,col,color,initialColor);
        for(auto p:internal){
            grid[p.first][p.second]=initialColor;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<0){
                    grid[i][j]*=-1;
                }
            }
        }
        return grid;


    }
};
```

#### Qn. 6 count no of connected component

Link: https://leetcode.com/problems/number-of-provinces/description/

```CPP
class Solution {
public:
    void dfs(vector<vector<int>> &graph,vector<bool> &visited,int start){
        visited[start]=true;
        int n=graph.size();
        for(int i=0;i<n;i++){
            if(graph[start][i] && visited[i]==false){
                dfs(graph,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int res=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                res++;
                dfs(isConnected,visited,i);
            }
        }
        return res;
    }
};

```

```CPP
#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int> > graph;
int v; // no of vertices
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }

}

void dfs(int node, unordered_set<int> &visited) {
    visited.insert(node);
    for(auto neighbor : graph[node]) {
        if(not visited.count(neighbor)) {
            dfs(neighbor, visited);
        }
    }
}

int connected_components() {
    int result = 0;
    unordered_set<int> visited;
    for(int i = 0; i < v; i++) { //O(v)
        // go to every vertex
        // if from a vertex we can initialse a dfs, we got one more cc
        if(visited.count(i) == 0) {
            result++;
            dfs(i, visited); //total O(v+E)
        }
    }
    return result;
}

int main() {

    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    while(e--) {
        int s, d;
        cin>>s>>d;
        add_edge(s, d, false);
    }
    cout<<connected_components()<<"\n";

    return 0;
}
```
