// Author: Surjeet Kumar Verma
//Link: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        for(unsigned int i=0;i<n;i++){
            if ((i>0) && (nums[i]==nums[i-1]))
                continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                 if(sum<0){
                    j++;
                }
                else if(sum>0) k--;
                else{
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(nums[j]==nums[j+1] && j<n-2) j++;
                    while(nums[k-1]==nums[k] && k>1) k--;
                    j++;
                    k--;
                }
            }
  
        }
        return res;
    }
};