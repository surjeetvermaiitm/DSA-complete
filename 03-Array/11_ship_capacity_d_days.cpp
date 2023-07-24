// Author: Surjeet Kumar Verma
//Link:https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int rtt(vector<int>& weights,int c){
        int sum_weight=0,ans=0;
        for(auto& weight:weights){
            if(sum_weight+weight<=c){
                sum_weight+=weight;
            }
            else{
                ans++;
                sum_weight=weight;
            }
        }
            return ans+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //P(x):rtt(x)<=days
        //FFFTTT
        //first T
        int max_ele=*max_element(weights.begin(),weights.end());
        int sum_ele=accumulate(weights.begin(),weights.end(),0);
        int lo=max_ele,hi=sum_ele,mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(rtt(weights,mid)<=days){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};

//
class Solution {
public:
    //function to give us required number of days for a certainc apacity of boat 
    int reqDays(int cap,vector<int> &arr){
        int n=arr.size();
        int reqDays=1;
        int remainingCap=cap;
        for(int i=0;i<n;i++){
            if(arr[i]<=remainingCap){
                remainingCap-=arr[i];
            }else{
                reqDays++;
                remainingCap=cap;
                remainingCap-=arr[i];
            }
        }
        return reqDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0,maxEle=-1;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            maxEle=max(maxEle,weights[i]);
        }
        int s=maxEle,e=sum,ans=sum;
        while(s<=e){
            int m=s+(e-s)/2;
            int d=reqDays(m,weights);
            if(d>days){
                s=m+1;
            }
            else{
                ans=min(ans,m);
                e=m-1;
            }
        }
        return ans;
    }
};