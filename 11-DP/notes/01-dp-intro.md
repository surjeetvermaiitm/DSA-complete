1. Fibonacci series
   fib(n)=fib(n-1)+fib(n-2)

recursive ->

```cpp
int fib(int n){
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}
```

DP - Top down (recursive)

```cpp
vector<int> dp(n+1,-1);
int fib(int n){
    if(n<=1) return n;
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=fib(n-1)+fib(n-2);
}

```

DP - Bottom up (Iterative)

```CPP
vector<int> dp(n+1,-1);
int fib(int n){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
```

space optimization in Bottom up

```CPP
int fib(int n){
    if(n<=1) return n;
    int secondlast=0;
    int last=1;
    int curr;
    for(int i=2;i<n+1;i++){
        curr=last+secondlast;
        secondlast=last;
        last=curr;
    }
    return curr;
}

```

2. Frog 2
   Link: https://atcoder.jp/contests/dp/tasks/dp_b

cost(i,j)=|h(i)-h(j)|
f(i)=min cost to reach the last stone from the ith
f(i)=min(cost(i,i+1)+f(i+1),cost(i,i+2)+f(i+2),...cost(i,i+k)f(i+k))

other notation
f(i)=min(|h(i)-h(j)|+f(i+j)) for all j belongs to [1,k] and i+j<=n-1

```CPP
#include<vector>
using namespace std;
//recursive
vector<int> h;
int k;
int f(int i){
    if(i>=h.size()){
        return INT_MAX;
    }
    if(i==h.size()-1){
        return 0;
    }
    int ans=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i+j>=h.size()) break;
        ans=min(ans,abs([h[i]-h[i+j]])+f(i+j));
    }
    return ans;

}
int main(){
    int n,k;
    cin>>n>>k;
    h.resize(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
   cout<<f(n);
    return 0;
}

//dp top down recursive

#include<vector>
using namespace std;
vector<int> h;
int k;
vector<int> dp;
int f(int i){
    if(i>=h.size()){
        return INT_MAX;
    }
    if(i==h.size()-1){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i+j>=h.size()) break;
        ans=min(ans,abs([h[i]-h[i+j]])+f(i+j));
    }
    return dp[i]=ans;

}
int main(){
    int n,k;
    cin>>n>>k;
    h.resize(n);
    dp.resize(n,-1);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
   cout<<f(0);
    return 0;
}
```
