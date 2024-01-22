/*
Link: https://atcoder.jp/contests/dp/tasks/dp_b
cost(i,j)=|h(i)-h(j)|
f(i)=min cost to reach the last stone from the ith 
f(i)=min(cost(i,i+1)+f(i+1),cost(i,i+2)+f(i+2),...cost(i,i+k)f(i+k))

other notation
f(i)=min(|h(i)-h(j)|+f(i+j)) for all j belongs to [1,k] and i+j<=n-1
*/
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
        ans=min(ans,abs([j[i]-h[i+j]])+f(i+j));
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
        ans=min(ans,abs([j[i]-h[i+j]])+f(i+j));
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

//bottom up iterative
#include<vector>
using namespace std;
vector<int> h;
int k;
vector<int> dp;
int f(int i){
    int n=h.size();
    dp.resize(100005,INT_MAX);
    //base 
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        for(int j=1;j<=k;j++){
            if(i+j>=h.size()) break;
            dp[i]=min(dp[i],abs(h[i]-h[i+j])+dp(i+j));
        }
    }
    return dp[0];

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