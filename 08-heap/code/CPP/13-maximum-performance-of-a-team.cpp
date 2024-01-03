//Link: https://leetcode.com/problems/maximum-performance-of-a-team/

#define pp pair<int,int>

bool cmp(pp p1,pp p2){
    return p1.first>p2.first;
}

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pp> v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end(),cmp);
        long long int ts=0;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        long long int ans=0;
        for(int i=0;i<n;i++){
            if(pq.size()==k){
                ts-=pq.top().first;
                pq.pop();
            }
            pq.push({v[i].second,v[i].first});
            ts+=v[i].second;
            ans=max(ans,(long long int)ts*v[i].first);
        }
        return ans % 1000000007;
        
    }
};