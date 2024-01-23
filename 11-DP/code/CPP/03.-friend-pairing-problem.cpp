// Link: https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

// https://www.geeksforgeeks.org/friends-pairing-problem/

#include <bits/stdc++.h>
using namespace std;

int f(n){
    if(n<=2) return n;
    return f(n-1)+(n-1)*f(n-2);

}

int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}