//Link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
    bool dfsAM(vector<vector<bool>> &graph,int curr,int dest,vector<bool> &visited,int n){
        if(curr==dest) return true;
        visited[curr]=true;
        for(int i=0;i<n;i++){
            if(graph[curr][i] && !visited[i]){           
                if(dfsAM(graph,i,dest,visited,n)){
                    return true;
                }
            }
        }
        return false;
    }
    bool bfsAM(vector<vector<bool>> &graph,int src,int dest,vector<bool> &visited,int n){
        queue<int> q;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(curr==dest) return true;
            for(int i=0;i<n;i++){
                if(graph[curr][i] && !visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        return false;
    }
     bool dfsAL(unordered_map<int,vector<int>> &graph,int curr,int dest,vector<bool> &visited,int n){
        if(curr==dest) return true;
        visited[curr]=true;
        for(auto nbr:graph[curr]){
            if(!visited[nbr]){           
                if(dfsAL(graph,nbr,dest,visited,n)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //Adjacency matrix TLE
        // vector<vector<bool>> graphAM(n,vector<bool>(n,false));
        // for(auto edge:edges){
        //     int u=edge[0];
        //     int v=edge[1];
        //     graphAM[u][v]=true;
        //     graphAM[v][u]=true;
        // }
        vector<bool> visited(n,false);
        // return dfsAM(graphAM,source,destination,visited,n);
        // return bfsAM(graphAM,source,destination,visited,n);

        //Adjacency List
        unordered_map<int,vector<int>> graphAL;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            graphAL[u].push_back(v);
            graphAL[v].push_back(u);

        }
        return dfsAL(graphAL,source,destination,visited,n);
        
    }
};