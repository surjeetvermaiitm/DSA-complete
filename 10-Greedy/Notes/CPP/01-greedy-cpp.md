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

2.
