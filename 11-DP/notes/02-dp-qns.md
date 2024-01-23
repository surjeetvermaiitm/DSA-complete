### DP

Link: https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
Q1. Given a number n count the number of binary strings of length n without consecutive 1
ex: n=3 -> 5 {000,001,010,100,101}

n=1->2 {0,1}
n=2->3 {00,01,10}
n=3 -> 5 {000,001,010,100,101}
n=4 ->8 {0000,0001,0010,0101,0100,1000,1010,0101}

f(n)=f(n-1)+f(n-2)

Q2. Friend pairing problem:
Link: https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

https://www.geeksforgeeks.org/friends-pairing-problem/

f(n) = f(n - 1) + (n - 1) \* f(n - 2)
proof: A,B,C,D here D have two choice (i D decide to go single, ii D decide to pair up with any one)

f(n)=returns the no. of ways such that n friends can go party
f(n-1) = when nth friend decided to go single
