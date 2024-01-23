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