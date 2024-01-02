//Link https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int ans=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                ans++;
                j++;
                i++;
            }else{
                j++;
            }
        }
        return ans;
        
    }
};