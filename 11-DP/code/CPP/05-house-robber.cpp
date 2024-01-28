//Link: https://leetcode.com/problems/house-robber/
//Top down
class Solution {
public:
    vector<int> dp;
    int f(vector<int> & arr, int i){
        int n=arr.size();
        if(i==n-1){
            dp[n-1]=arr[n-1];
            return arr[n-1];
        }
        if(i==n-2) {
            dp[n-2]=max(arr[n-2],arr[n-1]);
            return dp[n-2];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        return dp[i]=max(arr[i]+f(arr,i+2),f(arr,i+1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.clear();
        dp.resize(n+1,-1);
        return f(nums,0);
    }
};

//Bottom up
class Solution {
public:
    vector<int> dp;
    int f(vector<int> & arr, int i){
        int n=arr.size();
        if(i==n-1){
            dp[n-1]=arr[n-1];
            return arr[n-1];
        }
        if(i==n-2) {
            dp[n-2]=max(arr[n-2],arr[n-1]);
            return dp[n-2];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        return dp[i]=max(arr[i]+f(arr,i+2),f(arr,i+1));
    }
    int fbottomup(vector<int> &arr){
        int n=arr.size();
        if(n==1) return arr[0];
        dp.clear();
        dp.resize(n);
        dp[n-1]=arr[n-1];
        dp[n-2]=max(arr[n-1],arr[n-2]);
        for(int i=n-3;i>=0;i--){
            dp[i]=max(arr[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.clear();
        dp.resize(n+1,-1);
        // return f(nums,0);
        return fbottomup(nums);
    }
};