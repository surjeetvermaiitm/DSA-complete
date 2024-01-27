//Link: https://leetcode.com/problems/find-center-of-star-graph/description/
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> e1=edges[0];
        vector<int> e2=edges[1];
        // if(e1[0]==e2[0]) return e1[0];
        // if(e1[0]==e2[1]) return e1[0];
        // if(e1[1]==e2[0]) return e1[1];
        // if(e1[1]==e2[1]) return e1[1];

        int ans=(e1[0]==e2[0] || e1[0]==e2[1])?e1[0]:e1[1];
       return ans; 
    }
};