//Link: https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool cmp(int x,inty){
    return x>y;
}

//T -> mlogm + nlogn
//space -> O(1) 
//sort and 2 pointer
ll minCostToBreakGrid(int n,int m,vector<ll> &vertical,vector<ll>&horizontal){
    sort(vertical.begin(),vertical.end(),cmp);//desc
    sort(horizontal.begin(),horizontal.end(),cmp);
    int hz=1,vr=1;
    int h=0;
    int v=0;
    ll ans=0;
    while(h<horizontal.size() and v<vertical.size()){
        if(vertical[v]>horizontal[h]){
            ans+=vertical[v]*vr;
            hz++;
            v++;
        }else{
            ans+=horizontal[h]*hz;
            vr++;
            h++;   
        }
    }
    while(h<horizontal.size()){
        ans+=horizontal[h]*hz;
            vr++;
            h++;  
    }
    while(v<vertical.size()){
       ans+=vertical[v]*vr;
        hz++;
        v++; 
    }
    return ans;


}