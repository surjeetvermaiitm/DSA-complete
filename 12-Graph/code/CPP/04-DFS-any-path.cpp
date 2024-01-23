#include <bits/stdc++.h>
using namespace std;

//T= O(V+E)
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