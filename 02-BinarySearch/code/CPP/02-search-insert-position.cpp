//Link: https://leetcode.com/problems/search-insert-position/description/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //P(X)=x<k
        //TTFF
        //First F
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        return nums[n-1]<target?n:l;
        
    }
};