//Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //first p(x)=x>=k 
        //FFFTTT
        // First T


        //last p(x)=x>k
        //FFFTTT
        //last F
        
        vector<int> ans;
        int n=nums.size();
        if(n==0) return {-1,-1};
        int l=0,h=n-1,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(nums[mid]>=target){
                h=mid;
            }else{
                l=mid+1;
            }
        }
        if(nums[l]==target){
            ans.push_back(l);
        }else{
            return {-1,-1};
        }
        
        h=n-1;
        while(l<h){
            mid=l+(h-l+1)/2;
            if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid;
            }
        }
        ans.push_back(l);
        

        return ans;
        
    }
};