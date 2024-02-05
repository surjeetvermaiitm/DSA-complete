//Link: https://leetcode.com/problems/sum-of-two-integers/description/

class Solution {
public:
    int getSum(int a, int b) {
        return log2(pow(2,a)*pow(2,b));
        // return log2((1<<a)*(1<<b));
        //xor will give answer without carry
        //(a&b)<<1 will give one carry
        int carry;
        while(b!=0){
            carry=(a&b)<<1;
            a=a^b;
            b=carry;
        }
        return a;


    }
};