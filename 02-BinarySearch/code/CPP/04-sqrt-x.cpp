//Link: https://leetcode.com/problems/sqrtx/description/
class Solution {
public:
    int mySqrt(int x) {
        // p(x)=x*x<=k
        //TTTFFF
        //Last T
        int l=1,h=x/2,mid;
        if(x<2) return x;
        while(l<h){
            mid=l+(h-l+1)/2;
            if(mid<=x/mid){
                l=mid;
            }else{
                h=mid-1;
            }
        }
        return l;
        
    }
};