//Link: https://leetcode.com/problems/arranging-coins/
class Solution {
public:
    int arrangeCoins(int n) {
        //p(x)=x*(x+1)/2 <=n
        //TTTFFF
        //Last T
        long long int l=1,h=n-1,mid;
        while(l<h){
            mid=l+(h-l+1)/2;
            if(mid*(mid+1)/2<=n){
                l=mid;
            }else{
                h=mid-1;
            }
        }

        return l;
        
    }
};