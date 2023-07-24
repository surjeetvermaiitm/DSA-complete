// Author: Surjeet Kumar Verma
// Link: https://leetcode.com/problems/two-sum/submissions/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=target-nums[i];
            if(m.find(x)!=m.end()){
                res.push_back(i);
                res.push_back(m[x]);
            }
            m[nums[i]]=i;
        }
        return res;
    }
};

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash={}
        for i,num in enumerate(nums):
            diff=target-num
            if diff in hash:
                return [hash[diff],i]
            hash[num]=i
        return
