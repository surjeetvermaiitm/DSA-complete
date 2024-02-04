//Link: https://leetcode.com/problems/number-of-1-bits/description/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
            count++;
            n=n&(n-1);
        }
        return count;
        
    }
};
//T=No of set bits