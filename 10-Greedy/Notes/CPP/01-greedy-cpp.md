# Greedy

- sorting (custom cmp)
- priority queue
-

Q1. Maximize sum of array after k negotiation

Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

```cpp
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        int total=0;

        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }

        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());//O(n)

        // for(int i=0;i<nums.size();i++){
        //     pq.push(nums[i]);
        // }

        while(k--){ //O(klogn + n)
            int ele=pq.top();
            pq.pop();
            total -=ele;
            pq.push(-1*ele);
            total += -1*ele;
        }

        return total;
    }
};
```

2. Fractional knapsack

value (profit) / weight ratio should be more

- sort in decreasing order by value/weight ratio

```cpp
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &p1,pair<int,int> &p2){
    //pair<int,int> first -> value, second ->weight

    //default x<y //increasing order


    double r1 = (p1.first*1.0)/(p1.second*1.0);
    double r1 = (p2.first*1.0)/(p2.second*1.0);

    return r1>r2; // decreasing order
}

double fractionalKnapsack(vector<int> &profit,vector<int> &weights,int n,int W){
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        arr.push_back({profit[i],weights[i]});
    }
    sort(arr.begin(),arr.end(),cmp);
    double res=0;
    for(int i=0;i<n;i++){
        if(arr[i].second <=W){
            res +=arr[i].first;
            W-=arr[i].second;
        }else{
            res += (arr[i].first*1.0)*W/(arr[i]*second*1.0);
            W=0;
            break;
        }
    }
    return res;
}
```
