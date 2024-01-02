//Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
// Appoach 1
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

// Approach 2 using index

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