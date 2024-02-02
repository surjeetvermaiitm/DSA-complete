//Link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
    private boolean dfsAM(boolean[][] graph,int curr,int dest,boolean[] visited,int n){
        if(curr==dest){
            return true;
        }
        visited[curr]=true;
        for(int i=0;i<n;i++){
            if(graph[curr][i]==true && !visited[i]){
                if(dfsAM(graph,i,dest,visited,n)){
                    return true;
                }
            }
        }

        return false;
    }
    private boolean bfsAM(boolean[][] graph,int src,int dest,boolean[] visited,int n){
        Queue<Integer> q=new LinkedList<>();
        q.add(src);
        visited[src]=true;
        while(!q.isEmpty()){
            int curr=q.remove();
            if(curr==dest) return true;
            for(int i=0;i<n;i++){
                if(graph[curr][i]==true && !visited[i]){
                    q.add(i);
                    visited[i]=true;
                }
            }
        }

        return false;
    }
    private boolean dfsAL(Map<Integer,List<Integer>> graph,int curr,int dest,boolean[] visited,int n){
        if(curr==dest){
            return true;
        }
        visited[curr]=true;

        for(int nbr:graph.get(curr)){
            if(!visited[nbr]){
                if(dfsAL(graph,nbr,dest,visited,n)){
                    return true;
                }
            }
        }

        return false;
    }
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        //Adjecency matrix Memory limit exceeded
        // boolean [][]graphAM=new boolean[n][n];
        // for(boolean[] row:graphAM){
        //     Arrays.fill(row,false);
        // }
        // for(int [] edge:edges){
        //     int u=edge[0];
        //     int v=edge[1];
        //     graphAM[u][v]=true;
        //     graphAM[v][u]=true;
        // }
        boolean[] visited=new boolean[n];
        // return dfsAM(graphAM,source,destination,visited,n);
        // return bfsAM(graphAM,source,destination,visited,n);

        //Adjacency List
        Map<Integer,List<Integer>> graphAL=new HashMap<>();
        for(int[] edge:edges){
            int u=edge[0];
            int v=edge[1];
            graphAL.computeIfAbsent(u,value->new ArrayList<>()).add(v);
            graphAL.computeIfAbsent(v,value->new ArrayList<>()).add(u);
        }
        return dfsAL(graphAL,source,destination,visited,n);
        
    }
}