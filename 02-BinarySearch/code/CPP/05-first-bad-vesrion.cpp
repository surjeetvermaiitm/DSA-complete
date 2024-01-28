//Link: https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //FFFTTT
        //First T
        int l=1,h=n,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(isBadVersion(mid)){
                h=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
        
    }
};