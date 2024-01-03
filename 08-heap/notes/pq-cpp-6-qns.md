1. Find K pairs with smallest sum
   Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

Approach 1

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) { // time complexity is O(m*nlogk), m = nums1 size, n = nums2 size
        priority_queue<pair<int,pair<int,int>>> pq;  // default: the greatest comes top
        for(int i=0;i<nums1.size();i++) {
            for(int j=0;j<nums2.size();j++) {
                int sum=nums1[i]+nums2[j];
                if (pq.size()<k) {
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if (sum<pq.top().first) {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                } else {
                    break;  // save time! since we don't need to traverse the rest of vector 2
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```

Approach 2

```cpp
#define pp pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // // time complexity is O(m*nlogk), m = nums1 size, n = nums2 size
        // priority_queue<pair<int,pair<int,int>>> pq;  // default: the greatest comes top
        // for(int i=0;i<nums1.size();i++) {
        //     for(int j=0;j<nums2.size();j++) {
        //         int sum=nums1[i]+nums2[j];
        //         if (pq.size()<k) {
        //             pq.push({sum,{nums1[i],nums2[j]}});
        //         }
        //         else if (sum<pq.top().first) {
        //             pq.pop();
        //             pq.push({sum,{nums1[i],nums2[j]}});
        //         } else {
        //             break;  // save time! since we don't need to traverse the rest of vector 2
        //         }
        //     }
        // }
        // vector<vector<int>> ans;
        // while(!pq.empty()) {
        //     ans.push_back({pq.top().second.first, pq.top().second.second});
        //     pq.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;


        priority_queue<pp,vector<pp>,greater<pp>> pq;//min heap
        for(int i=0;i<nums1.size();i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        vector<vector<int>> res;
        pp ans;
        while(k-- and !pq.empty()){
            ans=pq.top();
            pq.pop();
            int sm=ans.first;
            int nums1Idx=ans.second.first;
            int nums2Idx=ans.second.second;
            res.push_back({nums1[nums1Idx],nums2[nums2Idx]});
            if(nums2Idx+1<nums2.size()){
                pq.push({nums1[nums1Idx]+nums2[nums2Idx+1],{nums1Idx,nums2Idx+1}});
            }
        }
        return res;

    }
};
```

Qn 2:
Sort character by freq
Link: https://leetcode.com/problems/sort-characters-by-frequency/

```cpp
#define pp pair<int,char>

class Solution {
public:
    string frequencySort(string s) {
        //using sort

        // vector<int> freq(256,0);
        // for(auto ch:s) freq[ch]++;
        // sort(s.begin(),s.end(),[=](char a,char b){
        //     if(freq[a]==freq[b]) return a<b;
        //     return freq[a]>freq[b];
        // });

        // return s;

        //usinh pq
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pp> pq;
        for(auto el:mp){
            char key=el.first;
            int val=el.second;
            pq.push({val,key});
        }
        string res="";
        while(not pq.empty()){
            pp curr=pq.top();
            pq.pop();
            for(int i=0;i<curr.first;i++){
                res+=curr.second;
            }
        }
        return res;

    }
};
```

Qn3.
Link: https://leetcode.com/problems/top-k-frequent-words/

```cpp
#define pp pair<int,string>
class cmp{
    public:
    bool operator()(pp p,pp q){
        if(p.first==q.first){
            return p.second>q.second;//ascending order
        }else{
            return p.first<q.first;//descending order
        }
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto word:words){
            mp[word]++;
        }
        vector<string> res;
        priority_queue<pp,vector<pp>,cmp> pq;
        for(auto el:mp){
            pq.push({el.second,el.first});

        }
        while(k-- && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;


    }
};
```

Qn 4. Min Operators to halve array sum

Link: https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

```cpp
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double total=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            pq.push(nums[i]*1.0);
        }
        double required_sum=total/2.0;
        while(total>required_sum and not pq.empty()){
            double el=pq.top();
            pq.pop();
            total-=el/2.0;
            pq.push(el/2.0);
            ans++;

        }
        return ans;

    }
};
```

Qn 5. Maximum performance of a team
Link: https://leetcode.com/problems/maximum-performance-of-a-team/

```cpp
#define pp pair<int,int>

bool cmp(pp p1,pp p2){
    return p1.first>p2.first;
}

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pp> v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end(),cmp);
        long long int ts=0;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        long long int ans=0;
        for(int i=0;i<n;i++){
            if(pq.size()==k){
                ts-=pq.top().first;
                pq.pop();
            }
            pq.push({v[i].second,v[i].first});
            ts+=v[i].second;
            ans=max(ans,(long long int)ts*v[i].first);
        }
        return ans % 1000000007;

    }
};

```

Qn 6. Furthest building you can reach
Link: https://leetcode.com/problems/furthest-building-you-can-reach/
