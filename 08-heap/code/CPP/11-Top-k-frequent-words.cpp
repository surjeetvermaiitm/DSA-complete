//Link: https://leetcode.com/problems/top-k-frequent-words/

#define pp pair<int,string>
class cmp{
    public:
    bool operator()(pp p,pp q){
        if(p.first==q.first){
            return p.second>q.second;//ascending order
        }else{
            return p.first<q.first;//descending order
        }
    } 
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto word:words){
            mp[word]++;
        }
        vector<string> res;
        priority_queue<pp,vector<pp>,cmp> pq;
        for(auto el:mp){
            pq.push({el.second,el.first});
            
        }
        while(k-- && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

        
    }
};