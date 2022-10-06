// Author: Surjeet Kumar Verma
// Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
//Link: https://leetcode.com/problems/contiguous-array/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> m;
        int psum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            psum+=A[i];
            if(m.find(psum)!=m.end()){
                ans=max(ans,i-m[psum]);
            }
            else{
                m[psum]=i;
            }
            if(psum==0){
                ans=max(ans,i+1);
            }
            
        }
        return ans;
    }
};

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