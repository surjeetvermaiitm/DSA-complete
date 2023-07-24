// Author: Surjeet Kumar Verma
// Link:https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// Link: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0,k=0,j=n-1;
        while(i<=j){
            if(nums[i]==2){
                swap(nums[i],nums[j]);
                j--;
            }
            else if(nums[i]==0){
                swap(nums[k],nums[i]);
                k++;
                i++;
            }
            else{
                i++;
            }
        }
    }
};