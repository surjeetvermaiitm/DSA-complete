//Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02
class Solution {
public:

    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(n==0) return  ans;
        unordered_map<int,int> freq;
        for(auto &num:nums){
            if(freq.find(num)!=freq.end()){
                freq[num]++;
            }else{
                freq.insert({num,1});
            }
        }
        
        while(!freq.empty()){
            vector<int> v;
            for(auto it = freq.begin(); it != freq.end(); ){
                int val=it->first;
                if(it->second==1){
                    v.push_back(val);
                    it=freq.erase(it);//vvi
                }else{
                    v.push_back(val);
                    freq[val]--;
                    it++;
                } 
            }
            ans.push_back(v);
        }
        return ans;   
    }
};