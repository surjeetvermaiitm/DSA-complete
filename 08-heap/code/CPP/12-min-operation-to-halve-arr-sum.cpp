//Link: https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double total=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            pq.push(nums[i]*1.0);
        }
        double required_sum=total/2.0;
        while(total>required_sum and not pq.empty()){
            double el=pq.top();
            pq.pop();
            total-=el/2.0;
            pq.push(el/2.0);
            ans++;

        }
        return ans;
        
    }
};