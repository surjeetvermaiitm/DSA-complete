// arr -> -ve , +ve, 0
// n-> 10^5
// subset whose product is minimum. Return the product. (not subset)

// eg. [-1,-1,-2,4,3] = -24
// [-5,0]=-5
// [-9,0,-4,-3]=-60

// brute force -> 2^n

// greedy:
// no negative ->

// - zero available -> ans =0
// - zero not available -> ans= min positive val

// we have negative

// - even number of -ve -> product of all -ve except the largest -ve ele
// - odd number of -ve -> ans = product of all -ve x product of all +ve

#include<bits/stdc++.h>
using namespace std;

int minProduct(vector<int> &arr){
    int cn=0;
    int cz=0;
    int cp=0;
    int prod_pos=1;
    int prod_neg=1;
    int largestNegative=INT_MIN;

    for(int i=0;i<arr.size();i++){
        if(arr[i]<0) {
            cn++;
            prod_neg*=arr[i];
            largestNegative=max(largestNegative,arr[i]);
        }
        if(arr[i]>0){
            cp++;
            prod_pos*=arr[i];
        };
        if(arr[i]==0) cz++;
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            return *min_element(arr.begin(),arr.end());
        }
    }else{
        if(cn%2==0){
            //even
            return (prod_neg/largestNegative)*prod_pos;
        }else{
            //odd
            return prod_neg*prod_pos;
        }
    }
}


