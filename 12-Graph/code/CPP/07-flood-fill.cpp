//Link: https://leetcode.com/problems/flood-fill/description/
class Solution {
public:
    void dfs(vector<vector<int>>& image,int currRow,int currCol,int initialColor,int newColor){
        int n=image.size();
        int m=image[0].size();
        if(currRow<0 || currCol<0 || currRow>=n || currCol>m || image[currRow][currCol]!=initialColor || initialColor==newColor){
            return;
        }
        image[currRow][currCol]=newColor;
        dfs(image,currRow+1,currCol,initialColor,newColor);
        dfs(image,currRow,currCol+1,initialColor,newColor);
        dfs(image,currRow-1,currCol,initialColor,newColor);
        dfs(image,currRow,currCol-1,initialColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;   
    }
};
//
class Solution {
public:
    void dfs(vector<vector<int>>& image,int currRow,int currCol,int initialColor,int newColor){
        int n=image.size();
        int m=image[0].size();
        if(currRow<0 || currCol<0 || currRow>=n || currCol>m || image[currRow][currCol]!=initialColor || initialColor==newColor){
            return;
        }
        image[currRow][currCol]=newColor;
        dfs(image,currRow+1,currCol,initialColor,newColor);
        dfs(image,currRow,currCol+1,initialColor,newColor);
        dfs(image,currRow-1,currCol,initialColor,newColor);
        dfs(image,currRow,currCol-1,initialColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;   
    }
};