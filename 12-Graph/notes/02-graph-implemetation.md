### Graph Implementation

- 2 main elemental parts of graph
- vertices :Class
- edges :Class

#### 1. Edgelist representation

```CPP
class Node{
    int data;
}
class Edge{
    Node src;
    Node dest;
    int wt;
    bool directional;
}
class Graph{
    vector<Edge> edges;
    vector<Node> vertices;
}
```

Traditional Approach

#### 2. Adjacency List

- In this Approach we represent Graphs as a array of linked list.
- Array -> vertices
- LL -> neighbours info

- ith Index of Array represents neighbour of ith vertex. This neighbour info is stored in LL.
- Neighbour: Any node having direct edge from a vertex
  > What about directed and undirected weighted graph: Instead of storing an integer in the LL, we can store a pair. first->(neighbour),second->(weight of neighbour)

#### 3. Adjacency Map

- Array of unordered map
- Here we represent the graph in the form of array of hashmap/unordered_map.
- Array ->vertices, hashmap-> neighbour
- Any ith index of the array represent data of ith vertices
- v1:{{v3,w3},{v2,w2}}
- To find whether any vertex is neighbour of another vertex or not?

#### 4. Adjacency Matrix

- In this approach we represent the graph in a 2d array or matrix of VxV dimensions where v is the number of vertices.

```
adj[i][j]=1 (if edge from i to j)
adj[i][j]=0 (if no edge from i to j)

or
adj[i][j]=W
```

Graph:

1. Dense Graph: more edges (more connection)
2. Sparse Graph: less edges

#### 5. Incidence Matrix

- In this approach we prepare a VxE matrix where V is the number of vertices and E is the number of edges.
- M[i][j]=(1 if the ith vertex belongs to the jth edge)
- M[i][j]=(2 if the ith vertex belongs to the jth edge for self loop edge)
- In undirected graph: column sum = 2, Row sum=degree
