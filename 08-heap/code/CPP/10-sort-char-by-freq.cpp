//Link: https://leetcode.com/problems/sort-characters-by-frequency/description/
#define pp pair<int,char>

class Solution {
public:
    string frequencySort(string s) {
        //using sort

        // vector<int> freq(256,0);
        // for(auto ch:s) freq[ch]++;
        // sort(s.begin(),s.end(),[=](char a,char b){
        //     if(freq[a]==freq[b]) return a<b;
        //     return freq[a]>freq[b];
        // });
        
        // return s;

        //usinh pq
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pp> pq;
        for(auto el:mp){
            char key=el.first;
            int val=el.second;
            pq.push({val,key});
        }
        string res="";
        while(not pq.empty()){
            pp curr=pq.top();
            pq.pop();
            for(int i=0;i<curr.first;i++){
                res+=curr.second;
            }
        }
        return res;

    }
};