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