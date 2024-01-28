//Link: https://leetcode.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //p(x)=x>k
        //FFFTT
        //last F
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid;
        while(l<h){
            mid=l+(h-l+1)/2;
            if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid;
            }
        }
        return nums[l]==target?l:-1;
    }
};