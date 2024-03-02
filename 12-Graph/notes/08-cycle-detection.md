directed graph - > toplogical sort DAG kahn's algo

undirected graph-> BFS, DFS, DSU

### 1. Cycle detection using DSU

```CPP
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &parent, int x) {
    // TX:(log*n);
    // This method returns which group/cluster x belongs to
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

bool Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    // TX:(log*n);
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return true;
    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a] = b;
    }

    return false;
}


int main() {

    int n, m;
    cin>>n>>m;
    // n-> elements, m -> no of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while(m--) {
        int x, y;
        cin>>x>>y;
        bool b = Union(parent, rank, x, y);
        if(b == true) cout<<"Cycle detected\n";
    }

    return 0;
}
```

### 2. Cycle detection using DFS

```CPP
#include <bits/stdc++.h>
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

void display() {
    for(int i = 0; i < graph.size(); i++) {
        cout<<i<<" -> ";
        for(auto el : graph[i]) {
            cout<<el<<" , ";
        }
        cout<<"\n";
    }
}

bool dfs(int src, int parent, unordered_set<int> &vis) {
    vis.insert(src);
    for(auto neighbour : graph[src]) {
        if(vis.count(neighbour) and neighbour != parent) {
            // cycle detected
            return true;
        }
        if(!vis.count(neighbour)) {
            bool res = dfs(neighbour, src, vis);
            if(res == true) return true;
        }
    }
    return false;
}

bool has_cycle() {
    unordered_set<int> vis;
    for(int i = 0; i < v; i++) {
        if(!vis.count(i)) {
            bool result = dfs(i, -1, vis);
            if(result == true) return true;
        }
    }
    return false;
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
    // display();
    bool b = has_cycle();
    cout<<b<<"\n";

    return 0;
}
```

### 3. Cycle detection using BFS

```CPP
#include <bits/stdc++.h>
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

void display() {
    for(int i = 0; i < graph.size(); i++) {
        cout<<i<<" -> ";
        for(auto el : graph[i]) {
            cout<<el<<" , ";
        }
        cout<<"\n";
    }
}

bool bfs(int src) {
    unordered_set<int> vis;
    queue<int> qu;
    vector<int> par(v, -1);
    qu.push(src);
    vis.insert(src);
    while(not qu.empty()) {
        int curr = qu.front();
        qu.pop();
        for(auto neighbour : graph[curr]) {
            if(vis.count(neighbour) and par[curr] != neighbour) return true;
            if(!vis.count(neighbour)) {
                vis.insert(neighbour);
                par[neighbour] = curr;
                qu.push(neighbour);
            }
        }
    }
}

bool has_cycle() {
    unordered_set<int> vis;
    for(int i = 0; i < v; i++) {
        if(!vis.count(i)) {
            bool result = bfs(i);
            if(result == true) return true;
        }
    }
    return false;
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
    // display();
    bool b = has_cycle();
    cout<<b<<"\n";

    return 0;
}
```

### Qn Most stones removed with same row or column

Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
