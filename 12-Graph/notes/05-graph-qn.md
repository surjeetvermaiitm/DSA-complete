#### Q1. L-5 01 Matrix

Link: https://leetcode.com/problems/01-matrix/description/
Multisource BFS from 0

```CPP

```

#### Q2. Minimum Knight move

Link: https://leetcode.ca/all/1197.html

BFS
<i,j,step>

```CPP

```

#### Q3. Surrounded regions

Link: https://leetcode.com/problems/surrounded-regions/description/

```CPP
class Solution {
public:
    vector<vector<int>> nbrs={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>> &board,int i,int j,vector<vector<bool>> &visited){
        visited[i][j]=true;
        int m=board.size(),n=board[0].size();
        for(auto &nbr:nbrs){
            int x=i+nbr[0];
            int y=j+nbr[1];
            if(x<0 || y<0 || x>=m || y>=n || visited[x][y] || board[x][y]=='X')
                continue;
            dfs(board,x,y,visited);

        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        //top and down boundary
        for(int i=0;i<n;i++){
            if(visited[0][i]==false && board[0][i]=='O'){
                dfs(board,0,i,visited);
            }
            if(visited[m-1][i]==false && board[m-1][i]=='O'){
                dfs(board,m-1,i,visited);
            }
        }
        //left and right boundary
        for(int i=0;i<m;i++){
            if(visited[i][0]==false && board[i][0]=='O'){
                dfs(board,i,0,visited);
            }
            if(visited[i][n-1]==false && board[i][n-1]=='O'){
                dfs(board,i,n-1,visited);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                    board[i][j]='X';
                }
            }
        }


    }
};
```

#### Q4. Walls and gates Premium

Multi source BFS from Gates
Link: https://www.lintcode.com/problem/663/

#### Q5. Shortest Bridge

distinguish both island multi source BFS from boundary of one islands

Link: https://leetcode.com/problems/shortest-bridge/description/

![1707129395312](image/05-graph-qn/1707129395312.png)
