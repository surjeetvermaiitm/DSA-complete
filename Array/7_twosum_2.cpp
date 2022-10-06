// Author: Surjeet Kumar Verma
//Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int n=numbers.size();
        int i=0,j=n-1;
        while(i<j && i<n && j>=0){
            int sum=numbers[i]+numbers[j];
            if(sum==target){
                res.push_back(i+1);
                res.push_back(j+1);
                i++;
                j--;
            }
            else if(sum>target) j--;
            else i++;
        }
        return res;
    }
};

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l, r = 0, len(numbers) - 1
        
        while l < r: 
            cur_sum = numbers[l] + numbers[r]
            
            if cur_sum == target: return [l + 1, r + 1]
            
            elif cur_sum < target:
                l += 1
                
            else:
                r -= 1