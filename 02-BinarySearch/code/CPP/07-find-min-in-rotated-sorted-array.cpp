//Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        //P(x)=x>arr[n-1]
        //TTTFFF
        //First F

        int n=nums.size();
        int l=0,h=n-1,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(nums[mid]>nums[n-1]){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        return nums[l];
        
    }
};