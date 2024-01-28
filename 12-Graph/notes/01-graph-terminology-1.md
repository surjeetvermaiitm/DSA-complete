## Graph

- A graph is a collection of nodes where each node might or might not be point to other nodes. The node represent real life entities and are connected by edges representing relationship between the nodes and entities.

- Node / Vertices
- Edge

Applications:

- Google maps (shortest path)
- Split wise
- dependency resolution

## Mathematical defination of Graph

> G=(V,E) - Graph is an ordered pair(where order matters) of set V and set E represented by Vertices and edges respectively.

- V={v1,v2,v3,....vn}
- E={{v1,v2},{v2,v3},.....}

### Types of Graph

#### 1. On the basis of direction

- Directed Graph (Instagram)
- Undirected Graph (Facebook)

#### 2. On the basis of weight of edge

- Weighted Graph
- Unweighted Graph

### Graph Terminology

- Multigraph: An undirected graph in which multiple edges are allowed between two nodes.

- Simple Graph: An undirected graph in which both multiple edges and loops are not allowed

- Completed Graph: A complete graph is the one in which every node is directly connected to every other node. (A direct edge exist for every node pairs)

- Connected Graph: In this graph we have a direct or indirect path for every possible pairs of vertices.

- Path: Path Pn is a graph whose vertices can be arranged in sequence.

- Cycle: A cycle Cn is also a graph whose vertices can be arranged in cyclic sequence.

- DAG: (Directed Acyclic Graph): Directed and cyclic

- Degree: Degree of a vertice in a Graph is the total number of edges incident towards it or away from it.

  - Directed
    - Indegree: In directed graph indegree of a vertex is total no of incoming edges.
    - OutDegree: In Directed Graph outdegree of a vertex is a total no of outgoing edges.
  - Undirected (All edges)

- Trees: It is a connected Graph with no cycles. If we remove all cycles from a graph we get a Tree. (Connected Acyclic Graph). If we remove an edge from a tree, It no more remains connected and should be called forest.

- Connected components: If there is a disconnected graph then the set of vertices which are connected forms a connected component.

### Facts

- Tree : |E| = |V|-1
- Forest: |E| = |V|-1 (max)
- Connected Graph: |E|=|V|-1 (min)
- Undirected Complete Graph: |E|=|v| C 2 (max)
- Directed Complete Graph: |E|=|v|\*(|v|-1) (max)

#### Connected components

- It is a subset of the given graph that has vertices between which there is always a path.
