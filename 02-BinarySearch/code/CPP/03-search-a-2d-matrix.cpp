//Link: https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //p(x)=x>=k;
        //FFTT
        //first T
        int m=matrix.size();
        int n=matrix[0].size(); 
        if(m==0 || n==0) return false;
        int l=0;
        int h=m*n-1;
        int mid;
        while(l<h){
            mid=l+(h-l)/2;
            int i=mid/n;
            int j=mid%n;
            if(matrix[i][j]>=target){
                h=mid;
            }else{
                l=mid+1;
            }
        }
        return matrix[l/n][l%n]==target;
        
    }
};