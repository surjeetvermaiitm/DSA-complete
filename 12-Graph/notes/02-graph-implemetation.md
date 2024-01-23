### Graph Implementation

- 2 main elemental parts of graph
- vertices :Class
- edges :Class

#### 1. Edgelist representation

```CPP
class Node{
    int data;
}
class Edge{
    Node src;
    Node dest;
    int wt;
    bool directional;
}
class Graph{
    vector<Edge> edges;
    vector<Node> vertices;
}
```

Traditional Approach

#### 2. Adjacency List

- In this Approach we represent Graphs as a array of linked list.
- Array -> vertices
- LL -> neighbours info

- ith Index of Array represents neighbour of ith vertex. This neighbour info is stored in LL.
- Neighbour: Any node having direct edge from a vertex
  > What about directed and undirected weighted graph: Instead of storing an integer in the LL, we can store a pair. first->(neighbour),second->(weight of neighbour)

```CPP
#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;//no of vertices
void add_edge(int src,int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" --> "
        for(auto el:graph[i]){
            cout<<el<<" , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
       int s,d;
       cin>>s>>d;
       add_edge(s,d);
    }
    return 0;
}

```

weighted adjacency list

```CPP
#include <bits/stdc++.h>
using namespace std;

vector<list<pair<int,int>>> graph;
int v;//no of vertices
void add_edge(int src,int dest,int wt, bool bi_dir=true){
    graph[src].push_back({dest,wt});
    if(bi_dir){
        graph[dest].push_back({src,wt});
    }
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" --> "
        for(auto el:graph[i]){
            cout<<"("<<el.first<<" "<<el.second<<") , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<pair<int,int>>());
    int e;
    cin>>e;
    while(e--){
       int s,d,wt;
       cin>>s>>d>>wt;
       add_edge(s,d,wt);
    }
    return 0;
}
```

#### 3. Adjacency Map

- Array of unordered map
- Here we represent the graph in the form of array of hashmap/unordered_map.
- Array ->vertices, hashmap-> neighbour
- Any ith index of the array represent data of ith vertices
- v1:{{v3,w3},{v2,w2}}
- To find whether any vertex is neighbour of another vertex or not?

```CPP
#include <bits/stdc++.h>
using namespace std;

vector<unordered_map<int,int>> graph;
int v;//no of vertices
void add_edge(int src,int dest,int wt, bool bi_dir=true){
    graph[src][dest]=wt;
    if(bi_dir){
         graph[dest][src]=wt;
    }
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" --> "
        for(auto el:graph[i]){
            cout<<"("<<el.first<<" "<<el.second<<") , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v,unordered_map<int,int>());
    int e;
    cin>>e;
    while(e--){
       int s,d,wt;
       cin>>s>>d>>wt;
       add_edge(s,d,wt);
    }
    return 0;
}
```

#### 4. Adjacency Matrix

- In this approach we represent the graph in a 2d array or matrix of VxV dimensions where v is the number of vertices.

```
adj[i][j]=1 (if edge from i to j)
adj[i][j]=0 (if no edge from i to j)

or
adj[i][j]=W
```

Graph:

1. Dense Graph: more edges (more connection)
2. Sparse Graph: less edges

#### 5. Incidence Matrix

- In this approach we prepare a VxE matrix where V is the number of vertices and E is the number of edges.
- M[i][j]=(1 if the ith vertex belongs to the jth edge)
- M[i][j]=(2 if the ith vertex belongs to the jth edge for self loop edge)
- In undirected graph: column sum = 2, Row sum=degree
