//Link: https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    vector<vector<int>> nbrs={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>> &grid,int i,int j,vector<vector<bool>> &visited){
        visited[i][j]=true;
        int m=grid.size(),n=grid[0].size();
        //perform dfs on neighbors
        for(auto& nbr:nbrs){
            int x=i+nbr[0];
            int y=j+nbr[1];
            if(x<0 || y<0 || x>=m || y>=n || visited[x][y] ||grid[x][y]=='0')
                continue;
            dfs(grid,x,y,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    res++;
                    dfs(grid,i,j,visited);
                   
                }
            }
        }
        return res;
    }
};

//BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int cc = 0; // stores the number of connected components
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == '0') {
                    // it is a water body
                    continue;
                }
                // new unvisited land piece found, i.e. new connected component
                cc++;
                grid[r][c] = '0'; // mark it visited
                queue<pair<int, int> > qu;
                qu.push({r, c}); // store the src node
                while(not qu.empty()) {
                    auto curr = qu.front(); // get one node from queue
                    qu.pop();
                    // go to all unvisited neighbours of the curr node
                    int currRow = curr.first;
                    int currCol = curr.second;
                    // check up
                    if(currRow - 1 >= 0 and grid[currRow - 1][currCol] == '1') {
                        qu.push({currRow-1, currCol});
                        grid[currRow - 1][currCol] = '0';
                    }
                    // check down
                    if(currRow + 1 < rows and grid[currRow + 1][currCol] == '1') {
                        qu.push({currRow+1, currCol});
                        grid[currRow + 1][currCol] = '0';
                    }
                    // check left
                    if(currCol - 1 >= 0 and grid[currRow][currCol-1] == '1') {
                        qu.push({currRow, currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                    // check right
                    if(currCol + 1 < cols and grid[currRow][currCol+1] == '1') {
                        qu.push({currRow, currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }
                }
            }
        }
        
        return cc;
    }
};
int main() {

    return 0;
}