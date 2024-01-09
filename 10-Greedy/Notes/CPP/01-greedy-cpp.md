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
//T -> O(nlogn)
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

Qn 3. Maximum Units on a truck
Link: https://leetcode.com/problems/maximum-units-on-a-truck/

```cpp
bool cmp(vector<int> &a,vector<int> &b){
    return a[1]>b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sort based on numberOfUnitPerBox
        // use fractional knapsack
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int profit=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                profit+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }else{
                profit+=truckSize*boxTypes[i][1];
                truckSize=0;
                break;
            }
            if(truckSize==0) break;
        }

        return profit;
    }
};
```

Qn 4. Boats to save people

Link: https://leetcode.com/problems/boats-to-save-people/

Approach 1 -> sort and 2 pointer

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {


        sort(people.begin(),people.end());

        int i = 0, j = people.size() - 1,cnt = 0;

        while(i <= j)
        {

            if(people[i] + people[j] <= limit)
            {
                ++i;
                --j;
            }

            else
                --j;

            ++cnt;
        }

        return cnt;

    }

};
```

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {


        sort(people.begin(),people.end());

        int i = 0, j = people.size() - 1,boat = 0;

        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            }
            else{
                j--;
            }
            boat++;
        }
        return boat;
    }

};
```

### Qn 5. Minimum Product Subset

arr -> -ve , +ve, 0
n-> 10^5
subset whose product is minimum. Return the product. (not subset)

eg. [-1,-1,-2,4,3] = -24
[-5,0]=-5
[-9,0,-4,-3]=-60

brute force -> 2^n

greedy:
no negative ->

- zero available -> ans =0
- zero not available -> ans= min positive val

we have negative

- even number of -ve -> product of all -ve except the largest -ve ele
- odd number of -ve -> ans = product of all -ve x product of all +ve

```cpp
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
```

### Qn 6. Minimum Cost to cut a board into square

Link: https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/

```cpp
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
```

### Qn 7. COnstruct string with repeat limit

//Link: https://leetcode.com/problems/construct-string-with-repeat-limit/

```cpp
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<char,int>> pq;
        for(auto p:mp){
            pq.push(p);
        }
        string res="";
        while(!pq.empty()){
            auto largest=pq.top();
            pq.pop();
            int len=min(repeatLimit,largest.second);
            for(int i=0;i<len;i++){
                res+=largest.first;
            }
            pair<char,int> secondLargest;
            if(largest.second-len>0){
                if(!pq.empty()){
                    secondLargest=pq.top();
                    pq.pop();
                    res+=secondLargest.first;
                }else{
                    return res;
                }
                if(secondLargest.second-1>0){
                    pq.push({secondLargest.first,secondLargest.second-1});
                }
                pq.push({largest.first,largest.second-len});
            }
        }
        return res;


    }
};
```
