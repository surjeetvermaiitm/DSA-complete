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

#### Qn.7. Number of Islands

Link: https://leetcode.com/problems/number-of-islands/description/

```CPP
class Solution {
public:
    vector<vector<int>> nbrs={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>> &grid,int i,int j,vector<vector<bool>> &visited){
        visited[i][j]=true;
        int m=grid.size(),n=grid[0].size();
        //perform dfs on neighbors
        for(auto& nbr:nbrs){
            int x=i+nbr[0];
            int y=j+nbr[1];
            if(x<0 || y<0 || x>=m || y>=n || visited[x][y] ||grid[x][y]=='0')
                continue;
            dfs(grid,x,y,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    res++;
                    dfs(grid,i,j,visited);

                }
            }
        }
        return res;
    }
};
```

BFS

```CPP
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int cc = 0; // stores the number of connected components
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == '0') {
                    // it is a water body
                    continue;
                }
                // new unvisited land piece found, i.e. new connected component
                cc++;
                grid[r][c] = '0'; // mark it visited
                queue<pair<int, int> > qu;
                qu.push({r, c}); // store the src node
                while(not qu.empty()) {
                    auto curr = qu.front(); // get one node from queue
                    qu.pop();
                    // go to all unvisited neighbours of the curr node
                    int currRow = curr.first;
                    int currCol = curr.second;
                    // check up
                    if(currRow - 1 >= 0 and grid[currRow - 1][currCol] == '1') {
                        qu.push({currRow-1, currCol});
                        grid[currRow - 1][currCol] = '0';
                    }
                    // check down
                    if(currRow + 1 < rows and grid[currRow + 1][currCol] == '1') {
                        qu.push({currRow+1, currCol});
                        grid[currRow + 1][currCol] = '0';
                    }
                    // check left
                    if(currCol - 1 >= 0 and grid[currRow][currCol-1] == '1') {
                        qu.push({currRow, currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                    // check right
                    if(currCol + 1 < cols and grid[currRow][currCol+1] == '1') {
                        qu.push({currRow, currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }
                }
            }
        }

        return cc;
    }
};
int main() {

    return 0;
}
```

#### Qn.8 Pacific Atlantic water flow

Link: https://leetcode.com/problems/pacific-atlantic-water-flow/description/

```CPP
class Solution {
public:
    vector<vector<int> > dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // i, j -> i+1, j -> i-1, j -> i, j-1 -> i, j+1
    int rows;
    int cols;
    vector<vector<int> > h;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        h = heights;
        queue<pair<int, int> > pacificbfs;
        queue<pair<int, int> > atlanticbfs;

        // steo of multisource bfs
        for(int i = 0; i < rows; i++) {
            pacificbfs.push({i, 0});
            atlanticbfs.push({i, cols-1});
        }

        for(int j = 1; j < cols; j++) {
            pacificbfs.push({0, j});
        }

        for(int j = 0; j < cols-1; j++) {
            atlanticbfs.push({rows-1, j});
        }

        vector<vector<bool> > pacific = bfs(pacificbfs);
        vector<vector<bool> > atlantic = bfs(atlanticbfs);

        vector<vector<int> > result;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pacific[i][j] and atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }

    vector<vector<bool> > bfs(queue<pair<int, int> > &qu) {
        vector<vector<bool> > visited(rows, vector<bool> (cols, false));
        while(not qu.empty()) {
            auto cell = qu.front();
            qu.pop();
            int i = cell.first;
            int j = cell.second;
            visited[i][j] = true;
            for(int d = 0; d < 4; d++) {
                int newRow = i+dir[d][0];
                int newCol = j+dir[d][1];
                if(newRow < 0 or newCol < 0 or newRow >= rows or newCol >= cols) continue; // you exited the grid
                if(visited[newRow][newCol]) continue;
                if(h[newRow][newCol] < h[i][j]) continue; // h[newRow][newCol] -> neighbours height, h[i][j] -> curr cell's heigh
                qu.push({newRow, newCol});
            }
        }
        return visited;
    }
};
```
