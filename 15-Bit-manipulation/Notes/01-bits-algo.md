#### Q1. Number of 1 Bits

Link: https://leetcode.com/problems/number-of-1-bits/description/

Brian Kernighan's algorithm

```CPP
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

```

#### Q2. Sum of two integers

Link: https://leetcode.com/problems/sum-of-two-integers/description/
