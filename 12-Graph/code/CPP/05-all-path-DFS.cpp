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