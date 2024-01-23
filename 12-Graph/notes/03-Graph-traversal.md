### Graph Traversal

- To read any graph we have two major techniques.

#### 1. BFS (Breadth first traversal/search)- Iterative

- In BFS we travel the immediate neighbours first together.
- To find shortest path in unweighted graph
- use queue
- process imediate neighbour

```CPP
#include <bits/stdc++.h>
using namespace std;

//T= O(V+E)
vector<list<int>> graph;
int v;//no of vertices
unordered_set<int> visited;
vector<vector<int>> res;
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
void bfs(int src,int dest,vector<int> &dist){
    queue<int> q;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src]=0;
    visited.insert(src);
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto nbr:graph[curr]){
            if(!visited.count(nbr)){
                q.push(nbr);
                visited.insert(nbr);
                dist[nbr]=dist[curr]+1;
            }
        }
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
       int s,d;
       cin>>s>>d;
       add_edge(s,d);
    }
    int x,y;
    cin>>x>>y;

    vector<int> dist;
    bfs(x,y,dist)
    for(auto path:dist){
        cout<<el<<" ";
    }
    return 0;
}
```

#### 2. DFS (Depth first traversal/search)-Recursive

- Given a graph, calculate all paths between two 2 veritices
- Given a graph check whether there is a path between any 2 vertices or not?

- Check if path exist:
- Simplest soln for any path problem would be if src and dest are neighbour.
- If there is a path from nbrs to dest then there will be a path from src to dest via the neighbour.

f(u,v) : whether there is a path from u to v or not?
f(u,v)={f(n1,v) or f(n2,v) or ........f(nk,v)} - n1,n2,...nk are imediate neighbours of u
visited set

1. Any path

```CPP
//T= O(V+E)
#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;//no of vertices
unordered_set<int> visited;
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
bool dfs(int curr,int end){
    if(curr==end) return true;
    visited.insert(curr);//mark visited
    for(auto neighbour:graph[curr]){
        if(not visited.count(neighbour)){
            bool res=dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;

}
bool anyPath(int src,int dest){
    return dfs(src,dest);

}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
       int s,d;
       cin>>s>>d;
       add_edge(s,d,false);
    }
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<"\n";
    return 0;
}
```

T= O(V+E)

2. All paths

```CPP
#include <bits/stdc++.h>
using namespace std;

//T= O(V+E)
vector<list<int>> graph;
int v;//no of vertices
unordered_set<int> visited;
vector<vector<int>> res;
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
void dfs(int curr,int end,vector<int> &path){
    if(curr==end){
        path.push_back(curr);
        res.pus_back(path);
        path.pop_back();
        // visited.erase(curr);
        return;
    }
    visited.insert(curr);//mark visited
    for(auto neighbour:graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour,end,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;

}
void allPath(int src,int dest){
    vector<int> v;
    dfs(src,dest,v);

}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
       int s,d;
       cin>>s>>d;
       add_edge(s,d);
    }
    int x,y;
    cin>>x>>y;
    allPath(x,y);
    for(auto path:res){
        for(auto el:path){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```
