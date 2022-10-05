// Author: Surjeet Kumar Verma 
// Link :https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            return myPow(1/x,abs(n));
        }
        if(n==0) return 1;
        if(n==1) return x;
        double p=myPow(x,n/2);
        if(n%2==0){
            return p*p;
        }
        else{
            return p*p*x;
        }
    }
};

class Solution
{
public:
  double myPow(double x, int n)
  {
    // base condition
    if (n == 0)
      return 1;

    // when n is negative then this if-statement will be execute
    if (n < 0)
    {
      x = 1 / x;
      n = abs(n);
    }
    double temp = myPow(x, n / 2);

    // if N is odd then we will have to multiply X
    if (n % 2 == 1)
      return temp * temp * x;

    return temp * temp;
  }
};

/*
    time complexity : O(log n)
    space complexity : O(log n)
*/

// O(n)
class Solution
{
public:
	long long Pow(int X, int N)
    {
        //  Base Case : If the value of N becomes Zero, then we return 1 as X ^ 0 = 1
        if(N==0)
            return 1;

        //  Ask Recursion to get previous answer
        long long partialAns = Pow(X,N-1);

        //  We multiply it with X to get the answer
        return X * partialAns;
    }
};