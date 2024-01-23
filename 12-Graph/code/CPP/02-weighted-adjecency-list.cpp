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