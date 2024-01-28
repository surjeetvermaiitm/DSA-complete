//Link: https://leetcode.com/problems/number-of-provinces/description/
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
//
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