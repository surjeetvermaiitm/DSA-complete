### Dijkstra for shortest path in undirected weighted

```CPP
#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int, int>
using namespace std;

vector<list<pp > > gr;
void add_edge(int u, int v, int wt, bool bidir=true) {
    gr[u].push_back({v, wt});
    if(bidir) {
        gr[v].push_back({u, wt});
    }
}

unordered_map<int, int> djikstra(int src, int n) { // O(VlogV + ElogV)
    priority_queue<pp, vector<pp> , greater<pp> > pq; // {wt, node}
    unordered_set<int> vis;
    vector<int> via(n+1);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) { // O(V)
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] = 0;
    while(!pq.empty()) { // O((V+E)logV)
        pp curr = pq.top();
        if(vis.count(curr.second)) {
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();

        for(auto neighbour : gr[curr.second]) {
            if(!vis.count(neighbour.first) and mp[neighbour.first] > mp[curr.second] + neighbour.second) {
                pq.push({mp[curr.second] + neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second] + neighbour.second;
            }
        }

    }
    return mp;

}

int main() {
    int n, m;
    cin>>n>>m;
    gr.resize(n, list<pp > ());
    while(m--) {
        int u, v, wt;
        cin>>u>>v>>wt;
        add_edge(u, v, wt);
    }
    int src;
    cin>>src;
    unordered_map<int, int> sp = djikstra(src, n);
    for(auto p : sp) {
        cout<<p.first<<" "<<p.second<<"\n";
    }
    int dest;
    cin>>dest;
    cout<<sp[dest]<<"\n";
    return 0;
}
```

### 2. Shortest path BFS (Undirected and unweighted)
```CPP
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
using namespace std;

vector<list<int> > graph;
unordered_set<int> visited;
vector<vector<int> > result;
int v; // no of vertices
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}

void bfs(int src, vector<int> &dist) {
    queue<int> qu;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    qu.push(src);
    while(not qu.empty()) {
        int curr = qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(auto neighbour : graph[curr]) {
            if(not visited.count(neighbour)) {
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
    cout<<"\n";
}


int main() {
    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    visited.clear();
    while(e--) {
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }
    int x;
    cin>>x;
    vector<int> dist;
    bfs(x, dist);
    for(int i = 0; i < dist.size(); i++) {
        cout<<dist[i]<<" ";
    }
    return 0;
}
```