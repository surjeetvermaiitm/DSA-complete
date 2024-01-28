//Link: https://leetcode.com/problems/coloring-a-border/description/
class Solution {
public:
    vector<pair<int,int>> internal;
    void dfs(vector<vector<int>>& grid, int row, int col, int color,int initialColor){
        int m=grid.size();
        int n=grid[0].size();
        if(row>m-1 || col>n-1 || row<0 || col<0 || grid[row][col]!=initialColor){
            return;
        }
        
           
        grid[row][col]=-color;
        dfs(grid,row+1,col,color,initialColor);
        dfs(grid,row,col+1,color,initialColor);
        dfs(grid,row-1,col,color,initialColor);
        dfs(grid,row,col-1,color,initialColor);

        //below code will be executed while coming back

        if(!(row==0 || col==0 || row==m-1 || col==n-1 || grid[row+1][col]!=-color || grid[row-1][col]!=-color || grid[row][col+1]!=-color || grid[row][col-1]!=-color)){
            internal.push_back({row,col});
        }
        
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color ) {
        int initialColor=grid[row][col];
        if(initialColor==color) return grid;
        int m=grid.size();
        int n=grid[0].size();
        
        dfs(grid,row,col,color,initialColor);
        for(auto p:internal){
            grid[p.first][p.second]=initialColor;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<0){
                    grid[i][j]*=-1;
                }
            }
        }
        return grid;

        
    }
};